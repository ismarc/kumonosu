#include "InternalMessageProcessor.h"
#include "internal_method_map.h"
#include "Server.h"

using namespace kumonosu;

InternalMessageProcessor::InternalMessageProcessor(RequestQueue* internalQueue,
                                                   RemoteRequestManagerHandler* rHandler,
                                                   LocalRequestManagerHandler* lHandler,
                                                   OutgoingClient* client) :
    _internalQueue(internalQueue),
    _remoteHandler(rHandler),
    _localHandler(lHandler),
    _client(client),
    _shutdown(false)
{
    pthread_mutex_init(&_runMutex, NULL);
    pthread_mutex_init(&_queuedItemMutex, NULL);
}

void
InternalMessageProcessor::setInternalQueue(RequestQueue* internalQueue)
{
    _internalQueue = internalQueue;
}

void
InternalMessageProcessor::setRemoteHandler(RemoteRequestManagerHandler* handler)
{
    _remoteHandler = handler;
}

void
InternalMessageProcessor::setLocalHandler(LocalRequestManagerHandler* handler)
{
    _localHandler = handler;
}

void
InternalMessageProcessor::setOutgoingClient(OutgoingClient* client)
{
    _client = client;
}

void
InternalMessageProcessor::run()
{
    int runfailed = -1;
    struct timespec check_timeout;
    // Verify internal data state is sane
    if (_internalQueue == NULL) {
        return;
    }

    clock_gettime(CLOCK_REALTIME, &check_timeout);

    runfailed = pthread_mutex_timedlock(&_runMutex, &check_timeout);

    if (runfailed) {
        return;
    }
    
    // Kinda hacky, is this a good way?
    // queueLock locks the lock.  RequestQueue unlocks the lock when
    // an item is added to the queue, allowing us to block until items
    // are ready to be processed.
    _internalQueue->queueLock(&_queuedItemMutex);
    while(!_shutdown) {
        struct timespec timeout;
        int result = -1;
        
        clock_gettime(CLOCK_REALTIME, &timeout);
        timeout.tv_sec += 10; // Wait 10 seconds for timeout
        
        result = pthread_mutex_timedlock(&_queuedItemMutex, &timeout);

        // timedlock returns 0 on success, other on error/timeout
        if (!result) {
            // Do the processing of the queue item here
            processReadyQueue();

            pthread_mutex_unlock(&_queuedItemMutex);
            _internalQueue->queueLock(&_queuedItemMutex);
        }
    }

    // Unlock the shutdown
    _shutdown = false;
    pthread_mutex_unlock(&_runMutex);
}

void
InternalMessageProcessor::shutdown()
{
    _shutdown = true;
}

void
InternalMessageProcessor::processReadyQueue()
{
    std::queue<queueItem*> itemQueue;

    // Verify internal data state is sane
    if (_internalQueue == NULL) {
        return;
    }

    // All internal items are service id 0
    itemQueue = _internalQueue->getItemQueue(0);

    while (!itemQueue.empty()) {
        processQueueItem(itemQueue.front());
        itemQueue.pop();
    }
}

void
InternalMessageProcessor::processQueueItem(queueItem* item)
{
    int methodId = item->methodId;
    int serverId = item->serverId;
    arguments argList = item->argList;

    switch (methodId) {
    case INTERNAL_METHOD_SHUTDOWN:
        _shutdown = true;
        break;
    case INTERNAL_METHOD_GET_SERVER_LIST:
        // Sends a GET_SERVER_RESPONSE method call 
        // If returnService is set in the call, send the response to
        // the contained service id
        int32_t returnServiceId = 0;
        for (int i = 0; i < argList.i32Args.size(); i++) {
            if (argList.i32Args[i].name == "returnService") {
                returnServiceId = argList.i32Args[i].value;
                break;
            }
        }
        getServerList(returnServiceId);
        break;
    }

}
    
void
InternalMessageProcessor::getServerList(int32_t serviceId)
{
    std::vector<Server> servers;
    queueItem* item = new queueItem();
    arguments args;

    if (_internalQueue == NULL) {
        return;
    }

    item->methodId = INTERNAL_METHOD_GET_SERVER_RESPONSE;

    if (_client != NULL) {
        servers = _client->getServerList();

        // Build the queueItem from the list of servers
        i32Arg count;
        count.name = "serverCount";
        count.value = servers.size();
        args.i32Args.push_back(count);
        // Add each server to the arguments
        // The argument map is:
        // i32Args: serverCount => count of servers
        // stringArgs: serverName => server address
        // i32Args: <servername>:port => server port
        // i32Args: <servername>:serviceid => service id (multiple
        // entries)
        // i32Args: <servername>:serverid => server id
        for (int i = 0; i < servers.size(); i++) {
            // Add the server address
            stringArg serverAddress;
            serverAddress.name = "serverName";
            serverAddress.value = servers[i].getServerAddress();
            args.stringArgs.push_back(serverAddress);
            // Add the server port
            i32Arg port;
            port.name = serverAddress.value + ":" + "port";
            port.value = servers[i].getServerPort();
            args.i32Args.push_back(port);
            // Add the server id
            i32Arg serverId;
            serverId.name = serverAddress.value + ":" + "serverid";
            serverId.value = servers[i].getServerId();
            args.i32Args.push_back(serverId);

            std::vector<int32_t> serviceIds = servers[i].getServiceIds();
            // Add the service ids
            for (int j = 0; j < serviceIds.size(); j++) {
                i32Arg serviceId;
                serviceId.name = serverAddress.value + ":" + "serviceid";
                serviceId.value = serviceIds[j];
                args.i32Args.push_back(serviceId);
            }
        }
    } else {
        i32Arg count;
        count.name = "serverCount";
        count.value = 0;
        args.i32Args.push_back(count);
    }

    _internalQueue->addItem(serviceId, item);
}
