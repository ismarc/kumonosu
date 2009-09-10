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
#include "clientlib/MethodHandler.h"


namespace kumonosu {
    namespace manager {
        class KumonosuManager;

        class KumonosuManager {
        public:
            KumonosuManager();
            KumonosuManager(std::string serverAddress, int32_t serverPort);
            ~KumonosuManager() {}

            void run();
            void stop();

            bool addServer(Server newServer);
            void addService(int32_t serviceId);
            void removeService(int32_t serviceId);

            // Callback methods
            void methodNotFound(arguments argList);
            void ping(arguments argList);
            void pong(arguments argList);
            void getServerList(arguments argList);
            void getServerListResponse(arguments argList);
            void getServiceList(arguments argList);
            void getServiceListResponse(arguments argList);
        private:
            void registerProcessorMethods();
            
            Client* _client;
            MessageProcessor<KumonosuManager>* _processor;
            std::vector<Server> _serverList;
            std::vector<int32_t> _localServices;
            
            pthread_mutex_t _runMutex;
            pthread_mutex_t _processorLock;
            pthread_mutex_t _serverListLock;
            bool _stop;
        };
    }
}

#endif 	    /* !KUMONOSUMANAGER_H_ */
