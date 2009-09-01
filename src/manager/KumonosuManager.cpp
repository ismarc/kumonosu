#include "KumonosuManager.h"
#include "MethodHandler.h"
#include "clientlib/Client.h"
#include "clientlib/MessageProcessor.h"
#include "internal_method_map.h"

using namespace kumonosu;
using namespace kumonosu::manager;

KumonosuManager::KumonosuManager(std::string serverAddress,
                                 int32_t serverPort)
{
    _client = new Client(0, serverAddress, serverPort);
    _processor = new MessageProcessor(this, &MethodHandler::methodNotFound);

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
    _processor = new MessageProcessor(this, &MethodHandler::methodNotFound);

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
    _processor->setMethodCallback(MethodHandler::MethodMap::GetServerList,
                                  this,
                                  &MethodHandler::getServerList);
    _processor->setMethodCallback(MethodHandler::MethodMap::GetServerResponse,
                                  this,
                                  &MethodHandler::getServerListResponse);
    _processor->setMethodCallback(MethodHandler::MethodMap::Ping,
                                  this,
                                  &MethodHandler::ping);
    _processor->setMethodCallback(MethodHandler::MethodMap::Pong,
                                  this,
                                  &MethodHandler::pong);
    _processor->setMethodCallback(MethodHandler::MethodMap::GetServiceList,
                                  this,
                                  &MethodHandler::getServiceList);
    _processor->setMethodCallback
        (MethodHandler::MethodMap::GetServiceListResponse,
         this,
         &MethodHandler::getServiceListResponse);
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
    std::string serverAddress;
    int32_t port;
    int32_t serviceId = -1;
    int32_t serverId = -1;
    i32Arg pingId;
    pingId.name = "pingId";
    pingId.value = -1;

    // ping should contain the server address, port and service id
    // Extract the server address
    for (int it = 0; it < argList.stringArgs.size(); it++) {
        if (argList.stringArgs[it].name == "serverAddress") {
            serverAddress = argList.stringArgs[it].value;
        }
    }

    // Extract the port and server id information
    for (int it = 0; it < argList.i32Args.size(); it++) {
        if (argList.i32Args[it].name == "port") {
            port = argList.i32Args[it].value;
        }
        if (argList.i32Args[it].name == "serviceId") {
            serviceId = argList.i32Args[it].value;
        }
        if (argList.i32Args[it].name == "pingId") {
            pingId.value = argList.i32Args[it].value;
        }
    }

    // Find the associated server
    for (int it = 0; it < _serverList.size(); it++) {
        if (_serverList[it].getServerAddress() == serverAddress &&
            _serverList[it].getServerPort() == port) {
            serverId = _serverList[it].getServerId();
            break;
        }
    }

    // Build the response
    queueItem item;
    item.methodId = MethodHandler::MethodMap::Pong;
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

    // FIXME: Should really build in a serialize/deserialize feature
    // to Server so that it generates the arguments (ie, no code
    // duplication).  Goes for a couple of other spots, too.
    queueItem item;
    item.methodId = MethodHandler::MethodMap::GetServerResponse;
    item.serverId = destServerId;

    i32Arg count;
    count.name = "serverCount";
    count.value = _serverList.size();
    item.argList.i32Args.push_back(count);

    // The argument map is:
    // i32Args: serverCount => count of servers
    // stringArgs: serverName => server address
    // i32Args: <servername>:port => server port
    // i32Args: <servername>:serviceid => service id (multiple
    // entries)
    // i32Args: <servername>:serverid => server id

    for (int i = 0; i < _serverList.size(); i++) {
        // Add the server address
        stringArg serverAddress;
        serverAddress.name = "serverName";
        serverAddress.value = _serverList[i].getServerAddress();
        item.argList.stringArgs.push_back(serverAddress);
        // add the server port
        i32Arg port;
        port.name = serverAddress.value + ":" + "port";
        port.value = _serverList[i].getServerPort();
        item.argList.i32Args.push_back(port);
        // Add the server id
        i32Arg serverId;
        serverId.name = serverAddress.value + ":" + "serverid";
        serverId.value = _serverList[i].getServerId();
        item.argList.i32Args.push_back(serverId);

        std::vector<int32_t> serviceIds = _serverList[i].getServiceIds();
        // Add the service ids
        for (int j = 0; j < serviceIds.size(); j++) {
            i32Arg serviceId;
            serviceId.name = serverAddress.value + ":" + "serviceid";
            serviceId.value = serviceIds[j];
            item.argList.i32Args.push_back(serviceId);
        }
    }

    _client->sendRequest(destServiceId, item);
}

void
KumonosuManager::getServerListResponse(arguments argList)
{
    std::vector<Server> newServerList;

    for (int it = 0; it < argList.stringArgs.size(); it++) {
        // This indicates the address of a server
        if (argList.stringArgs[it].name == "serverName") {
            Server server;
            std::string serverAddress = argList.stringArgs[it].value;
            int32_t serverPort = -1;
            int32_t serverId = -1;
            std::vector<int32_t> serviceIds;
            
            // Find the server id, port and service ids
            for (int i = 0; i < argList.i32Args.size(); i++) {
                if (argList.i32Args[i].name == serverAddress + ":serverid") {
                    server.setServerId(argList.i32Args[i].value);
                } else if (argList.i32Args[i].name == serverAddress + ":port") {
                    server.setServerPort(argList.i32Args[i].value);
                } else if (argList.i32Args[i].name ==
                           serverAddress + ":serviceid") {
                    serviceIds.push_back(argList.i32Args[i].value);
                }
            }

            // Fill out the server object
            server.setServerAddress(serverAddress);
            server.setServerPort(serverPort);
            server.setServerId(serverId);
            server.setServiceIds(serviceIds);
        }
    }

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
}

void
KumonosuManager::getServiceListResponse(arguments argList)
{
    // Do something with the returned data
}

