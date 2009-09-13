#include "ping_arguments.h"

using namespace kumonosu::manager;

ping_arguments::ping_arguments(arguments rhs)
{
    boolArgs = rhs.boolArgs;
    byteArgs = rhs.byteArgs;
    i16Args = rhs.i16Args;
    i32Args = rhs.i32Args;
    i64Args = rhs.i64Args;
    doubleArgs = rhs.doubleArgs;
    stringArgs = rhs.stringArgs;

    loadFromArguments();
}

ping_arguments::ping_arguments(std::string serverAddress,
                               int32_t serverPort,
                               int32_t serverId,
                               int32_t serviceId,
                               int32_t pingId) :
    _serverAddress(serverAddress),
    _serverPort(serverPort),
    _serverId(serverId),
    _serviceId(serviceId),
    _pingId(pingId)
{
    generateArguments();
}

void
ping_arguments::generateArguments()
{
    stringArg serverAddress;
    serverAddress.name = "serverAddress";
    serverAddress.value = _serverAddress;
    stringArgs.push_back(serverAddress);

    i32Arg serviceId;
    serviceId.name = "serviceId";
    serviceId.value = _serviceId;
    i32Args.push_back(serviceId);

    i32Arg serverPort;
    serverPort.name = "port";
    serverPort.value = _serverPort;
    i32Args.push_back(serverPort);

    i32Arg serverId;
    serverId.name = "serverId";
    serverId.value = _serverId;
    i32Args.push_back(serverId);
    
    i32Arg pingId;
    pingId.name = "pingId";
    pingId.value = _pingId;
    i32Args.push_back(pingId);
}

void
ping_arguments::loadFromArguments()
{
    //Extract the server address
    for (int it = 0; it < stringArgs.size(); it++) {
        if (stringArgs[it].name == "serverAddress") {
            _serverAddress = stringArgs[it].value;
            break;
        }
    }

    // Extract port, server id and ping id information
    for (int it = 0; it < i32Args.size(); it++) {
        if (i32Args[it].name == "port") {
            _serverPort = i32Args[it].value;
        } else if (i32Args[it].name == "serviceId") {
            _serviceId = i32Args[it].value;
        } else if (i32Args[it].name == "pingId") {
            _pingId = i32Args[it].value;
        }
    }
}

std::string
ping_arguments::getServerAddress()
{
    return _serverAddress;
}

int32_t
ping_arguments::getServerPort()
{
    return _serverPort;
}

int32_t
ping_arguments::getPingId()
{
    return _pingId;
}

int32_t
ping_arguments::getServiceId()
{
    return _serviceId;
}

int32_t
ping_arguments::getServerId()
{
    return _serverId;
}

