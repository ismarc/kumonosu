#include "KumonosuManager.h"
#include "PingArguments.h"
#include "ServerListArguments.h"
#include "ServiceListArguments.h"
#include "clientlib/Client.h"
#include "clientlib/MessageProcessor.h"
#include "clientlib/MethodHandler.h"
#include "ManagerMethodMap.h"
#include "internal_method_map.h"

using namespace kumonosu;
using namespace kumonosu::manager;

KumonosuManager::KumonosuManager(std::string serverAddress,
                                 int32_t serverPort)
{
    _client = new Client(0, serverAddress, serverPort);
    _processor = new MessageProcessor<KumonosuManager>
        (this, &KumonosuManager::methodNotFound);

    _processor->setClient(_client);
    registerProcessorMethods();

    pthread_mutex_init(&_runMutex, NULL);
    pthread_mutex_init(&_processorLock, NULL);
    pthread_mutex_init(&_serverListLock, NULL);
}

KumonosuManager::KumonosuManager()
{
    // The manager is service id 0
    _client = new Client(0);
    _processor = new MessageProcessor<KumonosuManager>
        (this, &KumonosuManager::methodNotFound);

    _processor->setClient(_client);
    registerProcessorMethods();

    pthread_mutex_init(&_runMutex, NULL);
    pthread_mutex_init(&_processorLock, NULL);
    pthread_mutex_init(&_serverListLock, NULL);
}

void
KumonosuManager::run()
{
    // Don't start running if already running
    int runfailed = -1;
    struct timespec check_timeout;

    clock_gettime(CLOCK_REALTIME, &check_timeout);
    runfailed = pthread_mutex_timedlock(&_runMutex, &check_timeout);

    if (runfailed) {
        return;
    }

    while (!_stop) {
        pthread_mutex_lock(&_processorLock);

        _processor->processPendingItems(-1);

        pthread_mutex_unlock(&_processorLock);
        sleep(1);
    }

    // Unlock the stop
    _stop = false;
    pthread_mutex_unlock(&_runMutex);
}

void
KumonosuManager::stop()
{
    _stop = true;
}

bool
KumonosuManager::addServer(Server newServer)
{
    bool result = true;

    for (int it = 0; it < _serverList.size(); it++) {
        if (_serverList[it] == newServer) {
            result = false;
        }
    }

    if (result) {
        _serverList.push_back(newServer);
    }

    return result;
}

/**
 *  Private methods
 */
void
KumonosuManager::registerProcessorMethods()
{
    _processor->setMethodCallback(ManagerMethodMap::IMGetServerList,
                                  &KumonosuManager::getServerList);
    _processor->setMethodCallback(ManagerMethodMap::IMGetServerResponse,
                                  &KumonosuManager::getServerListResponse);
    _processor->setMethodCallback(ManagerMethodMap::Ping,
                                  &KumonosuManager::ping);
    _processor->setMethodCallback(ManagerMethodMap::Pong,
                                  &KumonosuManager::pong);
    _processor->setMethodCallback(ManagerMethodMap::GetServiceList,
                                  &KumonosuManager::getServiceList);
    _processor->setMethodCallback
        (ManagerMethodMap::GetServiceListResponse,
         &KumonosuManager::getServiceListResponse);
}

void
KumonosuManager::addService(int32_t serviceId)
{
    // Don't allow duplicates
    bool add_id = true;

    for (int i = 0; i < _localServices.size(); i++) {
        if (_localServices[i] == serviceId) {
            add_id = false;
            break;
        }
    }

    if (add_id) {
        _localServices.push_back(serviceId);
    }
}

void
KumonosuManager::removeService(int32_t serviceId)
{
    for (int i = 0; i < _localServices.size(); i++) {
        if (_localServices[i] == serviceId) {
            _localServices.erase(_localServices.begin() + i);
            break;
        }
    }
}

/**
 *  Callback methods for handling message processing
 */
void
KumonosuManager::methodNotFound(arguments argList)
{
    // Should log or generate a response or something
}

void
KumonosuManager::ping(arguments argList)
{
    PingArguments pingItem;
    pingItem.loadFromArguments(argList);
    pingItem.loadServerId(_serverList);

    int32_t serverId = pingItem.getServerId();
    int32_t serviceId = pingItem.getServiceId();
    i32Arg pingId;
    pingId.name = "pingId";
    pingId.value = pingItem.getPingId();

    // Build the response
    queueItem item;
    item.methodId = ManagerMethodMap::Pong;
    item.serverId = serverId;
    item.argList.i32Args.push_back(pingId);
    _client->sendRequest(serviceId, item);

}

void
KumonosuManager::pong(arguments argList)
{
    // Once something initiates a far end ping, this should be updated
    // to reflect a successful ping.
}

void
KumonosuManager::getServerList(arguments argList)
{
    int32_t destServerId = -1;
    int32_t destServiceId = -1;
    for (int i = 0; i < argList.i32Args.size(); i++) {
        if (argList.i32Args[i].name == "serverid") {
            destServerId = argList.i32Args[i].value;
        }
        if (argList.i32Args[i].name == "serviceid") {
            destServiceId = argList.i32Args[i].value;
        }
    }

    queueItem item;
    item.methodId = ManagerMethodMap::IMGetServerResponse;
    item.serverId = destServerId;

    i32Arg count;
    count.name = "serverCount";
    count.value = _serverList.size();
    item.argList.i32Args.push_back(count);

    ServerListArguments serverItem(_serverList);
    serverItem.addToArguments(&item.argList);

    _client->sendRequest(destServiceId, item);
}

void
KumonosuManager::getServerListResponse(arguments argList)
{
    std::vector<Server> newServerList;

    ServerListArguments serverArgs;
    serverArgs.loadFromArguments(argList);
    newServerList = serverArgs.getServerList();

    // Protect via multiple accesses
    pthread_mutex_lock(&_serverListLock);

    // Now that we have the list of servers, merge it with the known
    // list, not allowing for duplicates
    for (int i = 0; i < _serverList.size(); i++) {
        for (int j = 0; j < newServerList.size(); j++) {
            if (newServerList[j] == _serverList[i]) {
                newServerList.erase(newServerList.begin() + j);
            }
        }
    }

    for (int j = 0; j < newServerList.size(); j++) {
        _serverList.push_back(newServerList[j]);
    }

    pthread_mutex_unlock(&_serverListLock);
}

void
KumonosuManager::getServiceList(arguments argList)
{
    // Get a list of all local services and send a
    // getServiceListResponse to the calling server

    int32_t destServerId = -1;
    int32_t destServiceId = -1;
    for (int i = 0; i < argList.i32Args.size(); i++) {
        if (argList.i32Args[i].name == "serverid") {
            destServerId = argList.i32Args[i].value;
        }
        if (argList.i32Args[i].name == "serviceid") {
            destServiceId = argList.i32Args[i].value;
        }
    }

    queueItem item;
    item.methodId = ManagerMethodMap::GetServiceListResponse;
    item.serverId = destServerId;

    i32Arg count;
    count.name = "serviceCount";
    count.value = _localServices.size();
    item.argList.i32Args.push_back(count);

    ServiceListArguments serviceItem(_localServices);
    serviceItem.addToArguments(&item.argList);

    _client->sendRequest(destServiceId, item);
}

void
KumonosuManager::getServiceListResponse(arguments argList)
{
    // Do something with the returned data
}

