/*
** OutgoingClient.h
** 
** Made by Matthew Brace
** Login   <mbrace@godwin.lan>
** 
** Started on  Fri Jul 31 01:05:35 CDT 2009 Matthew Brace
** Last update Sun Aug  2 18:06:47 CDT 2009 Matthew Brace
*/

#ifndef   	OUTGOINGCLIENT_H_
#define   	OUTGOINGCLIENT_H_

#include "RequestQueue.h"
#include "RemoteServer.h"

namespace kumonosu {
    //! Manages remote server connections and processes sending queueItems.
    /*!
     *  \class OutgoingClient
     *  
     *  OutgoingClient is a service for processing the actual sending
     *  of requests to remote servers.  It processes items in the
     *  outgoing queue and sends them to the appropriate servers.
     *  Items are not processed or sent until run() is called.  Once
     *  called, the system will loop over checking for items in the
     *  outgoing queue and sending them until shutdown() is called.
     *  Once shutdown() is called, the object is still valid and
     *  subsequent calls to run() will start sending objects again.
     *  Note that queueItems destined for a service id of 0 must have
     *  a remote server id specified or they will be consumed and
     *  discarded.
     *  
     *  \author Matt Brace
     */
    class OutgoingClient {
    public:
        //! Initializes internal data objects and sets the queue to check.
        /*!
         *  Initializes internal data objects and prepares the system
         *  for a call to run().  Processing does not begin with a
         *  call to the constructor.
         *  \param queue the RequestQueue object that will
         *  contain/contains outgoing requests to process.
         */
        OutgoingClient(RequestQueue* queue);

        //! Sets the RequestQueue for outgoing requests.
        /*!
         *  Assigns the specified RequestQueue for processing outgoing
         *  requests.
         *  \param queue the RequestQueue to assign.
         */
        void setOutgoingQueue(RequestQueue* queue);

        //! Creates a remote server connection and adds to the list.
        /*!
         *  Creates a RemoteServer object based on supplied parameters
         *  and assigns it as a destination for the specified
         *  identifiers.
         *  \param serverId the id to associate with the server for
         *  requests with service id 0.
         *  \param serviceIds a std::vector containing the service ids
         *  to associate with the server.
         *  \param serverAddress the server address for the remote
         *  server.
         *  \param serverPort the server port for the remote server.
         */
        void addServer(int32_t serverId,
                       std::vector<int32_t> serviceIds,
                       std::string serverAddress,
                       int32_t serverPort);

        //! Removes a server from the associations.
        /*!
         *  Removes a server from association with the server id and
         *  service ids.  The server object is then destroyed, closing
         *  and freeing the connection.  
         */
        void removeServer(int32_t serverId);

        //! Starts processing of outgoing requests.
        /*!
         *  Initiates a loop that processes all outgoing requests for
         *  service ids that have an associated RemoteServer and all
         *  requests for a service id of 0 (using the supplied server
         *  id).  The OutgoingClient does not provide any
         *  multi-threading on its own, however, it includes
         *  protections that make it thread safe.  A mutex is used so
         *  that once run() is called, any subsequent calls have no
         *  effect.  RequestQueue notification locks are used for
         *  blocking behavior so that the OutgoingClient doesn't need
         *  to use an explicit wait or sleep to prevent spinning.  a
         *  pthread_mutex_timedlock of 10 seconds is used so that
         *  shutdown commands can break the loop from processing.
         *  Once started, the OutgoingClient will run until shutdown()
         *  is called.
         *  
         */
        void run();

        //! Stops processing of outgoing requests
        /*!
         *  Sets the flag that indicates that processing should stop.
         *  Due to the architecture of the run() loop, any outstanding
         *  requests will be processed prior to shutting down.
         */
        void shutdown();
    private:
        //! Internal only method, processes outgoing queue items.
        void processOutgoingQueue();
        
        RequestQueue* _outgoingQueue;
        bool _shutdown;
        std::map<int32_t, RemoteServer*> _serviceMap;
        std::map<int32_t, RemoteServer*> _serverMap;
        
        pthread_mutex_t _runMutex;
        pthread_mutex_t _queueMutex;
    };
}

#endif 	    /* !OUTGOINGCLIENT_H_ */
