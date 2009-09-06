#include "PingArguments.h"

using namespace kumonosu;
using namespace kumonosu::manager;

PingArguments::PingArguments() :
    _port(0),
    _pingId(-1),
    _serviceId(-1),
    _serverId(-1)
{
}

PingArguments::PingArguments(std::string serverAddress,
                             int32_t serverPort,
                             int32_t serviceId,
                             int32_t pingId) :
    _serverAddress(serverAddress),
    _port(serverPort),
    _serviceId(serviceId),
    _pingId(pingId),
    _serverId(-1)
{
}

PingArguments::~PingArguments()
{
}

void
PingArguments::addToArguments(arguments* args)
{
    if (args == NULL) {
        return;
    }
    
    // Add the address
    stringArg serverAddress;
    serverAddress.name = "serverAddress";
    serverAddress.value = _serverAddress;
    args->stringArgs.push_back(serverAddress);
    
    // Add the service id
    i32Arg serviceId;
    serviceId.name = "serviceId";
    serviceId.value = _serviceId;
    args->i32Args.push_back(serviceId);
    
    // Add the port
    i32Arg serverPort;
    serverPort.name = "port";
    serverPort.value = _port;
    args->i32Args.push_back(serverPort);
    
    i32Arg pingId;
    pingId.name = "pingId";
    pingId.value = _pingId;
    args->i32Args.push_back(pingId);
}

void
PingArguments::loadFromArguments(arguments args)
{
    // Extract the server address
    for (int it = 0; it < args.stringArgs.size(); it++) {
        if (args.stringArgs[it].name == "serverAddress") {
            _serverAddress = args.stringArgs[it].value;
            break;
        }
    }

    // Extract port, server id and ping id information
    for (int it = 0; it < args.i32Args.size(); it++) {
        if (args.i32Args[it].name == "port") {
            _port = args.i32Args[it].value;
        } else if (args.i32Args[it].name == "serviceId") {
            _serviceId = args.i32Args[it].value;
        } else if (args.i32Args[it].name == "pingId") {
            _pingId = args.i32Args[it].value;
        }

        if (_port != -1 &&
            _serviceId != -1 &&
            _pingId != -1) {
            break;
        }
    }
}

void
PingArguments::loadServerId(std::vector<Server> serverList)
{
    for (int it = 0; it < serverList.size(); it++) {
        if (serverList[it].getServerAddress() == _serverAddress &&
            serverList[it].getServerPort() == _port) {
            _serverId = serverList[it].getServerId();
            break;
        }
    }
}

std::string
PingArguments::getServerAddress()
{
    return _serverAddress;
}

int32_t
PingArguments::getServerPort()
{
    return _port;
}

int32_t
PingArguments::getPingId()
{
    return _pingId;
}

int32_t
PingArguments::getServiceId()
{
    return _serviceId;
}

int32_t
PingArguments::getServerId()
{
    return _serverId;
}
