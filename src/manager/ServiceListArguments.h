/*
** ServiceListArguments.h
** 
** Made by Matthew Brace
** Login   <mbrace@godwin.lan>
** 
** Started on  Sun Sep  6 00:06:10 2009 Matthew Brace
** Last update Sun Sep  6 00:06:10 2009 Matthew Brace
*/

#ifndef   	SERVICELISTARGUMENTS_H_
#define   	SERVICELISTARGUMENTS_H_

#include "kumonosu_server_types.h"
#include "ProcedureArguments.h"

namespace kumonosu {
    namespace manager {
        class ServiceListArguments : public ProcedureArguments {
        public:
            ServiceListArguments();
            ServiceListArguments(std::vector<int32_t> services);
            ~ServiceListArguments();

            virtual void addToArguments(arguments* args);
            virtual void loadFromArguments(arguments args);
        private:
            std::vector<int32_t> _services;
        };
    }
}

#endif 	    /* !SERVICELISTARGUMENTS_H_ */
