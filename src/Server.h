/*
** Server.h
** 
** Made by Matthew Brace
** Login   <mbrace@godwin.lan>
** 
** Started on  Sun Aug 16 20:39:48 2009 Matthew Brace
** Last update Sun Aug 16 20:39:48 2009 Matthew Brace
*/

#ifndef   	SERVER_H_
#define   	SERVER_H_

#include "kumonosu_server_types.h"

namespace kumonosu {
    class Server {
    public:
        Server();
        ~Server() {}

        bool operator==(Server server)
        {
            return (this->_serverAddress == server.getServerAddress() &&
                    this->_serverPort == server.getServerPort() &&
                    this->_serviceIds == server.getServiceIds() &&
                    this->_serverId == server.getServerId());
        }

        void setServerAddress(std::string serverAddress);
        std::string changeServerAddress(std::string serverAddress);
        void setServerPort(int32_t serverPort);
        int32_t changeServerPort(int32_t serverPort);
        void setServiceIds(std::vector<int32_t> serviceIds);
        void addServiceId(int32_t serviceId);
        void removeServiceId(int32_t serviceId);
        void setServerId(int32_t serverId);
        int32_t changeServerId(int32_t serverId);
        std::string getServerAddress();
        int32_t getServerPort();
        std::vector<int32_t> getServiceIds();
        int32_t getServerId();
    private:
        std::string _serverAddress;
        int32_t _serverPort;
        std::vector<int32_t> _serviceIds;
        int32_t _serverId;
    };
}

#endif 	    /* !SERVER_H_ */
