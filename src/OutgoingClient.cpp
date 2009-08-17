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

    if (server == NULL) {
        return;
    }

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
        if (server == it->second) {
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

    // Make sure our internal state is sane
    if (_outgoingQueue == NULL) {
        return;
    }

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

    // Unlock the shutdown for restart
    _shutdown = false;
    pthread_mutex_unlock(&_runMutex);
}

void
OutgoingClient::shutdown()
{
    _shutdown = true;
}

std::vector<Server>
OutgoingClient::getServerList()
{
    std::vector<Server> return_list;

    // a single instance of each server is contained in _serverMap
    for (std::map<int32_t, RemoteServer*>::iterator it = _serverMap.begin();
         it != _serverMap.end();
         it++) {
        Server server;
        std::vector<int32_t> serviceIds;

        server.setServerId(it->first);

        // iterate over the service ids to pull the list for this server
        std::map<int32_t, RemoteServer*>::iterator service_it;

        for (service_it = _serviceMap.begin();
             service_it != _serviceMap.end();
             service_it++) {
            if (service_it->second == it->second) {
                serviceIds.push_back(it->first);
            }
        }

        server.setServiceIds(serviceIds);
        server.setServerAddress(it->second->getServerAddress());
        server.setServerPort(it->second->getServerPort());

        return_list.push_back(server);
    }

    return return_list;
}

void
OutgoingClient::processOutgoingQueue()
{
    if (_outgoingQueue == NULL) {
        return;
    }

    // Process all the known service ids that are pending being sent
    std::vector<int32_t> serviceIds = _outgoingQueue->getServiceIds();

    for (int32_t i = 0; i < serviceIds.size(); i++) {
        if (_serviceMap.find(serviceIds[i]) != _serviceMap.end()) {
            RemoteServer* server = _serviceMap.find(serviceIds[i])->second;
            std::queue<queueItem*> items;

            if (server == NULL) {
                continue;
            }
            
            items = _outgoingQueue->getItemQueue(serviceIds[i]);

            while (!items.empty() &&
                   items.front() != NULL) {
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

    while (!serverItems.empty() &&
           serverItems.front() != NULL) {
        queueItem item;
        item.methodId = serverItems.front()->methodId;
        item.serverId = serverItems.front()->serverId;
        item.argList = serverItems.front()->argList;
        serverItems.pop();
        
        if (_serverMap.find(item.serverId) != _serverMap.end()) {
            RemoteServer* server = _serverMap.find(item.serverId)->second;
            if (server != NULL) {
                server->sendRequest(0, item);
            }
        }
    }
}
