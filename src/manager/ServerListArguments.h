/*
** ServerListArguments.h
** 
** Made by Matthew Brace
** Login   <mbrace@godwin.lan>
** 
** Started on  Sat Sep  5 23:15:24 2009 Matthew Brace
** Last update Sat Sep  5 23:15:24 2009 Matthew Brace
*/

#ifndef   	SERVERLISTARGUMENTS_H_
#define   	SERVERLISTARGUMENTS_H_

#include "kumonosu_server_types.h"
#include "ProcedureArguments.h"
#include "Server.h"

namespace kumonosu {
    namespace manager {
        class ServerListArguments : public ProcedureArguments {
        public:
            ServerListArguments();
            ServerListArguments(std::vector<Server> servers);
            ~ServerListArguments();

            virtual void addToArguments(arguments* args);
            virtual void loadFromArguments(arguments args);
            std::vector<Server> getServerList();
        private:
            std::vector<Server> _servers;
        };
    }
}


#endif 	    /* !SERVERLISTARGUMENTS_H_ */
