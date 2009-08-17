/*
** KumonosuManager.h
** 
** Made by Matthew Brace
** Login   <mbrace@godwin.lan>
** 
** Started on  Sun Aug 16 18:34:58 2009 Matthew Brace
** Last update Sun Aug 16 18:34:58 2009 Matthew Brace
*/

#ifndef   	KUMONOSUMANAGER_H_
#define   	KUMONOSUMANAGER_H_

#include "Server.h"
#include "kumonosu_server_types.h"
#include "clientlib/Client.h"
#include "clientlib/MessageProcessor.h"

namespace kumonosu {
    namespace manager {
        class KumonosuManager {
        public:
            KumonosuManager();
            ~KumonosuManager() {}

            void run();
            void stop();
            
            // Callback methods
            void methodNotFound(arguments argList);
            void getServerListResponse(arguments argList);
        private:
            void registerProcessorMethods();
            
            Client* _client;
            MessageProcessor* _processor;
            std::vector<Server> _serverList;
            
            pthread_mutex_t _runMutex;
            pthread_mutex_t _processorLock;
            bool _stop;
        };
    }
}

#endif 	    /* !KUMONOSUMANAGER_H_ */
