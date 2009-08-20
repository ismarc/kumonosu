#include "KumonosuManager.h"
#include "MethodHandler.h"
#include "clientlib/Client.h"
#include "clientlib/MessageProcessor.h"
#include "internal_method_map.h"

using namespace kumonosu;
using namespace kumonosu::manager;

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
    // Should generate a pong call to the calling server
}

void
KumonosuManager::pong(arguments argList)
{
    // Mark the caller as a successful status thingy
}

void
KumonosuManager::getServerList(arguments argList)
{
    // Turn std::vector<Server> into arguments and send to the caller
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
