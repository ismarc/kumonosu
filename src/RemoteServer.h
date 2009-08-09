/*
** RemoteServer.h
** 
** Made by Matthew Brace
** Login   <mbrace@godwin.lan>
** 
** Started on  Mon Jul 27 23:19:47 CDT 2009 Matthew Brace
** Last update Sun Aug  2 17:29:40 CDT 2009 Matthew Brace
*/

#ifndef   	REMOTESERVER_H_
#define   	REMOTESERVER_H_

#include "RemoteRequestManager.h"
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
    //! Represents a connection to a remote server for sending requests.
    /*!
     *  \class RemoteServer
     *
     *  RemoteServer represents a single connection to a remote
     *  server, maintaining the connection for the life of the
     *  RemoteServer object.  The connection is initially established,
     *  but the object stays valid in existence even if the remote
     *  server connection is closed.
     *
     *  \author Matt Brace
     */
    class RemoteServer {
    public:
        //! Initializes internal data objects and establishes connection.
        /*!
         *  The initial connection is established in the constructor,
         *  however, the object stays valid even if the connection
         *  fails or is disconnected.
         *  \param serverAddress a std::string indicating the address
         *  to connect to.
         *  \param serverPort a 32 bit integer indicating the port on
         *  the remote server to connect.
         */
        RemoteServer(std::string serverAddress, int32_t serverPort);
        //! Cleans up internal data objects and closes the remote connection.
        ~RemoteServer();

        //! Sends a request to the associated remote server.
        /*!
         *  Sends a request for the specified service and item to the
         *  associated remote server.
         *  \param serviceId a 32 bit integer indicating the id of the
         *  service to associate with the request.
         *  \param item the queueItem to send to the remote server.
         *  \return true if the request was successful, false otherwise.
         */
        bool sendRequest(int32_t serviceId, queueItem item);

        //! Retrieves the associated server address.
        /*!
         *  Returns the std:string identifying the associated server
         *  address.
         *  \return the std::string for the associated server.
         */
        std::string getServerAddress();

        //! Retrieves the associated server port.
        /*!
         *  Returns the 32 bit integer identifying the associated
         *  port.
         *  \return the integer for the associated port.
         */
        int32_t getServerPort();
    private:
        void initializeClient();

        std::string _serverAddress;
        int32_t _serverPort;
        shared_ptr<TTransport> _socket;
        shared_ptr<TTransport> _transport;
        shared_ptr<TProtocol> _protocol;
        RemoteRequestManagerClient _client;
        pthread_mutex_t _clientMutex;
    };
    
} /* End namespace kumonosu */

#endif 	    /* !REMOTESERVER_H_ */
