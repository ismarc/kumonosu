#include "ServerListArguments.h"

using namespace kumonosu;
using namespace kumonosu::manager;

ServerListArguments::ServerListArguments()
{
}

ServerListArguments::ServerListArguments(std::vector<Server> servers) :
    _servers(servers)
{
}

ServerListArguments::~ServerListArguments()
{
}

void
ServerListArguments::addToArguments(arguments* args)
{
    for (int it; it < _servers.size(); it++) {
        stringArg serverAddress;
        serverAddress.name = "serverName";
        serverAddress.value = _servers[it].getServerAddress();
        args->stringArgs.push_back(serverAddress);

        i32Arg port;
        port.name = serverAddress.value + ":" + "port";
        port.value = _servers[it].getServerPort();
        args->i32Args.push_back(port);

        i32Arg serverId;
        serverId.name = serverAddress.value + ":" + "serverid";
        serverId.value = _servers[it].getServerId();
        args->i32Args.push_back(serverId);

        std::vector<int32_t> serviceIds = _servers[it].getServiceIds();
        for (int i = 0; i < serviceIds.size(); i++) {
            i32Arg serviceId;
            serviceId.name = serverAddress.value + ":" + "serviceid";
            serviceId.value = serviceIds[i];
            args->i32Args.push_back(serviceId);
        }
    }
}

void
ServerListArguments::loadFromArguments(arguments args)
{
    std::vector<Server> newServerList;

    for (int it = 0; it < args.stringArgs.size(); it++) {
        if (args.stringArgs[it].name == "serverName") {
            Server server;
            std::string serverAddress = args.stringArgs[it].value;
            int32_t serverPort = -1;
            int32_t serverId = -1;
            std::vector<int32_t> serviceIds;

            for (int i = 0; i < args.i32Args.size(); i++) {
                if (args.i32Args[i].name == serverAddress + ":serverid") {
                    server.setServerId(args.i32Args[i].value);
                } else if (args.i32Args[i].name == serverAddress + ":port") {
                    server.setServerPort(args.i32Args[i].value);
                } else if (args.i32Args[i].name ==
                           serverAddress + ":serviceid") {
                    serviceIds.push_back(args.i32Args[i].value);
                }
            }

            server.setServerAddress(serverAddress);
            server.setServiceIds(serviceIds);
        }
    }
    
    _servers = newServerList;
}

std::vector<Server>
ServerListArguments::getServerList()
{
    return _servers;
}
