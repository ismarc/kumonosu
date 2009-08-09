/*
** Client.h
** 
** Made by Matthew Brace
** Login   <mbrace@godwin.lan>
** 
** Started on  Mon Aug  3 20:36:23 2009 Matthew Brace
** Last update Mon Aug  3 20:36:23 2009 Matthew Brace
*/

#ifndef   	CLIENT_H_
#define   	CLIENT_H_

#include "LocalRequestManager.h"
#include "kumonosu_server_types.h"

#include <protocol/TBinaryProtocol.h>
#include <transport/TSocket.h>
#include <transport/TTransportUtils.h>
#include <pthread.h>

using namespace boost;
using namespace apache::thrift;
using namespace apache::thrift::protocol;
using namespace apache::thrift::transport;

namespace kumonosu {
    class Client {
    public:
        Client(int32_t serviceId);
        Client(int32_t serviceId, int32_t serverPort);
        Client(int32_t serviceId, std::string serverAddress, int32_t serverPort);
        ~Client();
        
        void connect();
        void disconnect();
        void setServerAddress(std::string serverAddress);
        void setServerPort(int32_t serverPort);
        
        bool sendRequest(int32_t serviceId, queueItem item);
        bool sendLocalRequest(queueItem item);
        queueItem getNextPendingItem();
        queueItemList getPendingItems();
        queueItemList getPendingItems(int32_t count);
    private:
        std::string _serverAddress;
        int32_t _serverPort;
        int32_t _serviceId;
        
        shared_ptr<TTransport> _socket;
        shared_ptr<TTransport> _transport;
        shared_ptr<TProtocol> _protocol;
        LocalRequestManagerClient _client;

        pthread_mutex_t _clientMutex;
    };
}

#endif 	    /* !CLIENT_H_ */
