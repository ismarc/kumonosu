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
    //! Provides an interface for a service to communicate.
    /*!
     *  \class Client
     *
     *  Client provides an interface for a service to communicate via
     *  a server with services running locally or remotely,
     *  transparent to the Client.  A service can use Client directly,
     *  or can use a convenience class for handling message processing
     *  (see MessageProcessor).
     *
     *  \author Matt Brace
     */
    class Client {
    public:
        //! Initializes the client
        /*!
         *  Initializes a client to process messages destined for the
         *  supplied service id.  Uses localhost:9191 for the server.
         *  \param serviceId the unique identifier for the service.
         */
        Client(int32_t serviceId);
        //! Initializes the client
        /*!
         *  Initializes a client to process messages destined for the
         *  supplied service id.  Uses a hostname of localhost.
         *  \param serviceId the unique identifier for the service.
         *  \param serverPort the port on localhost to connect to.
         */
        Client(int32_t serviceId, int32_t serverPort);
        //! Initializes the client
        /*!
         *  Initializes a client to process messages destined for the
         *  supplied service id.
         *  \param serviceId the unique identifier for the service.
         *  \param serverAddress the IP or hostname of the server to
         *  connect to.
         *  \param serverPort the port on the server to connect to.
         */
        Client(int32_t serviceId, std::string serverAddress, int32_t serverPort);
        ~Client();

        //! Opens a connection to the server
        /*!
         *  Client is intended to hold a connection open for extended
         *  periods of time (not on-demand for requests).  connect()
         *  establishes the connection.
         */
        void connect();
        //! Closes a connection to the server
        /*!
         *  Closes the connection to the server, used if the service
         *  needs to change details about the connection or close
         *  outgoing sockets.
         */
        void disconnect();
        //! Assigns the server IP or hostname to connect to.
        /*!
         *  Closes the connection if open and assigns the specified
         *  server address.  The connection is not reopened
         *  afterwards.
         *  \param serverAddress the IP or hostname to connect to.
         */
        void setServerAddress(std::string serverAddress);
        //! Assigns the server port to connect to.
        /*!
         *  Closes the connection if open and assigns the specified
         *  port to connect to.  The connection is not reopened
         *  afterwards.
         *  \param serverPort the port on the server to connect to.
         */
        void setServerPort(int32_t serverPort);

        //! Sends a queue item request to the server.
        /*!
         *  Sends a queue item request to the assigned server for
         *  dispatching to another service (as defined by the local
         *  handler interface).
         *  \param serviceId the unique identifier of the service to
         *  send the item to.
         *  \param item the queue item to the service.
         *  \return true if successful, false otherwise.
         */
        bool sendRequest(int32_t serviceId, queueItem item);
        //! Sends a queue item request destined for the local manager.
        /*!
         *  Sends a request destined for the local manager to
         *  process.  Note that this is not used for local services,
         *  this is intended for communication with the manager
         *  itself.
         *  \param item the queue item to the local server.
         *  \return true if successful, false otherwise.
         */
        bool sendLocalRequest(queueItem item);
        //! Retrieves the next item from the queue.
        /*!
         *  Retrieves the next item in the queue for the service id
         *  associated with this client.
         *  \return the queueItem for the next item or NULL if no
         *  items are in the queue.
         */
        queueItem getNextPendingItem();
        //! Retrieves all outstanding items from the queue.
        /*!
         *  Retrieves all items pending in the queue for the service
         *  id associated with this client.
         *  \return the queueItemList of pending items or an empty
         *  queueItemList.
         */
        queueItemList getPendingItems();
        //! Retrieves a maximum number of outstanding items from the queue.
        /*!
         *  Retrieves a maximum of count items from the queue for the
         *  service id associated with this client.
         *  \return the queueItemList of pending items or an empty
         *  queueItemList
         */
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
