#include "OutgoingClient.h"

using namespace kumonosu;

OutgoingClient::OutgoingClient(RequestQueue* queue) :
    _outgoingQueue(queue),
    _shutdown(false)
{
    pthread_mutex_init(&_runMutex, NULL);
    pthread_mutex_init(&_queueMutex, NULL);
}

void
OutgoingClient::setOutgoingQueue(RequestQueue* queue)
{
    _outgoingQueue = queue;
}

void
OutgoingClient::addServer(int32_t serverId,
                          std::vector<int32_t> serviceIds,
                          std::string serverAddress,
                          int32_t serverPort)
{
    RemoteServer* server = new RemoteServer(serverAddress, serverPort);

    _serverMap.insert(std::pair<int32_t, RemoteServer*>(serverId, server));

    for (int32_t i = 0; i < serviceIds.size(); i++) {
        _serviceMap.insert(std::pair<int32_t, RemoteServer*>(serviceIds[i], server));
    }
}

void
OutgoingClient::removeServer(int32_t serverId)
{
    RemoteServer* server = _serverMap.find(serverId)->second;
    std::map<int32_t, RemoteServer*>::iterator it;

    if (server == NULL) {
        return;
    }
    
    for (std::map<int32_t, RemoteServer*>::iterator it = _serviceMap.begin();
         it != _serviceMap.end();
         it++) {
        if (server = it->second) {
            _serviceMap.erase(it);
        }
    }
    
    it = _serverMap.find(serverId);
    _serverMap.erase(it);

    delete server;
    server = NULL;
}

void
OutgoingClient::run()
{
    // Check the run mutex, can only be running once
    int runfailed = -1;
    struct timespec check_timeout;
    clock_gettime(CLOCK_REALTIME, &check_timeout);

    runfailed = pthread_mutex_timedlock(&_runMutex, &check_timeout);

    if (runfailed) {
        return;
    }

    _outgoingQueue->queueLock(&_queueMutex);

    while(!_shutdown) {
        struct timespec timeout;
        int result = -1;

        clock_gettime(CLOCK_REALTIME, &timeout);
        timeout.tv_sec += 10; // Wait 10 seconds for timeout

        result = pthread_mutex_timedlock(&_queueMutex, &timeout);

        // timedlock returns 0 on success, other on error/timeout
        if (!result) {
            processOutgoingQueue();

            pthread_mutex_unlock(&_queueMutex);
            _outgoingQueue->queueLock(&_queueMutex);
        }
    }

    pthread_mutex_unlock(&_runMutex);
}

void
OutgoingClient::shutdown()
{
    _shutdown = true;
}

void
OutgoingClient::processOutgoingQueue()
{
    // Process all the known service ids that are pending being sent
    std::vector<int32_t> serviceIds = _outgoingQueue->getServiceIds();

    for (int32_t i = 0; i < serviceIds.size(); i++) {
        if (_serviceMap.find(serviceIds[i]) != _serviceMap.end()) {
            RemoteServer* server = _serviceMap.find(serviceIds[i])->second;
            std::queue<queueItem*> items;
            
            items = _outgoingQueue->getItemQueue(serviceIds[i]);

            while (!items.empty()) {
                queueItem item;
                item.methodId = items.front()->methodId;
                item.serverId = items.front()->serverId;
                item.argList = items.front()->argList;
                items.pop();
                
                server->sendRequest(serviceIds[i], item);
            }
        }
    }

    // Process all the items with a service id of 0 (unknown)
    std::queue<queueItem*> serverItems;
    serverItems = _outgoingQueue->getItemQueue(0);

    while (!serverItems.empty()) {
        queueItem item;
        item.methodId = serverItems.front()->methodId;
        item.serverId = serverItems.front()->serverId;
        item.argList = serverItems.front()->argList;
        serverItems.pop();
        
        if (_serverMap.find(item.serverId) != _serverMap.end()) {
            RemoteServer* server = _serverMap.find(item.serverId)->second;
            server->sendRequest(0, item);
        }
    }
}
