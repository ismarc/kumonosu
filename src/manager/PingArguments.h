/*
** PingArguments.h
** 
** Made by Matthew Brace
** Login   <mbrace@godwin.lan>
** 
** Started on  Sat Sep  5 21:44:38 2009 Matthew Brace
** Last update Sat Sep  5 21:44:38 2009 Matthew Brace
*/

#ifndef   	PINGARGUMENTS_H_
#define   	PINGARGUMENTS_H_

#include "kumonosu_server_types.h"
#include "ProcedureArguments.h"
#include "Server.h"

namespace kumonosu {
    namespace manager {
        class PingArguments : public ProcedureArguments {
        public:
            PingArguments();
            PingArguments(std::string serverAddress,
                          int32_t serverPort,
                          int32_t serviceId,
                          int32_t pingId);
            ~PingArguments();

            virtual void addToArguments(arguments* args);
            virtual void loadFromArguments(arguments args);
            void loadServerId(std::vector<Server> serverList);
            std::string getServerAddress();
            int32_t getServerPort();
            int32_t getPingId();
            int32_t getServiceId();
            int32_t getServerId();
        private:
            std::string _serverAddress;
            int32_t _port;
            int32_t _pingId;
            int32_t _serviceId;
            int32_t _serverId;
        };
    }
}

#endif 	    /* !PINGARGUMENTS_H_ */
