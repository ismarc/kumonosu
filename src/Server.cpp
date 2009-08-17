#include "Server.h"

using namespace kumonosu;

Server::Server()
{

}

void
Server::setServerAddress(std::string serverAddress)
{
    _serverAddress = serverAddress;
}

std::string
Server::changeServerAddress(std::string serverAddress)
{
    std::string old_address = _serverAddress;

    _serverAddress = serverAddress;

    return old_address;
}

void
Server::setServerPort(int32_t serverPort)
{
    _serverPort = serverPort;
}

int32_t
Server::changeServerPort(int32_t serverPort)
{
    int32_t old_port = _serverPort;

    _serverPort = serverPort;

    return old_port;
}

void
Server::setServiceIds(std::vector<int32_t> serviceIds)
{
    _serviceIds = serviceIds;
}

void
Server::addServiceId(int32_t serviceId)
{
    bool add_id = true;
    // Iterate over the vector so we don't end up with duplicates
    for (int i = 0; i < _serviceIds.size(); i++) {
        if (_serviceIds[i] == serviceId) {
            add_id = false;
            break;
        }
    }

    if (add_id) {
        _serviceIds.push_back(serviceId);
    }
}

void
Server::removeServiceId(int32_t serviceId)
{
    for (int i = 0; i < _serviceIds.size(); i++) {
        if (_serviceIds[i] == serviceId) {
            _serviceIds.erase(_serviceIds.begin() + i);
            break;
        }
    }
}

void
Server::setServerId(int32_t serverId)
{
    _serverId = serverId;
}

int32_t
Server::changeServerId(int32_t serverId)
{
    int32_t old_id = _serverId;

    _serverId = serverId;

    return old_id;
}

std::string
Server::getServerAddress()
{
    return _serverAddress;
}

int32_t
Server::getServerPort()
{
    return _serverPort;
}

std::vector<int32_t>
Server::getServiceIds()
{
    return _serviceIds;
}

int32_t
Server::getServerId()
{
    return _serverId;
}
