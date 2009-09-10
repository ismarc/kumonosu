/*
** InternalMessageProcessor.h
** 
** Made by Matthew Brace
** Login   <mbrace@godwin.lan>
** 
** Started on  Thu Jul 30 22:25:48 CDT 2009 Matthew Brace
** Last update Mon Aug 17 00:13:21 CDT 2009 Matthew Brace
*/

#ifndef   	INTERNALMESSAGEPROCESSOR_H_
#define   	INTERNALMESSAGEPROCESSOR_H_

#include "RequestQueue.h"
#include "RemoteRequestManagerHandler.h"
#include "LocalRequestManagerHandler.h"
#include "OutgoingClient.h"
#include "kumonosu_server_types.h"

namespace kumonosu {
    //! Processes items destined for the local server.
    /*!
     *  \class InternalMessageProcessor
     *
     *  InternalMessageProcessor is a service for handling requests
     *  destined for the local running server.  Items are not
     *  processed until run() is called.  Once called, the system will
     *  loop over checking for requests until shutdown() is called.
     *  The object is still valid after shutdown() is called, suitable
     *  to be restarted by calling run().
     *  
     *  \author Matt Brace
     */
    class InternalMessageProcessor {
    public:
        //! Initializes internal data objects.
        /*!
         *  Initializes internal data objects and prepares the system
         *  for a call to run().  Processing does not begin with a
         *  call to the constructor.
         *  \param internalQueue the RequestQueue for requests to be
         *  processed.
         *  \param rHandler the RemoteRequestManagerHandler for
         *  external requests.
         *  \param lHandler the LocalRequestManagerHandler for
         *  internal requests.
         *  \param client the OutgoingClient that manages RemoteServer
         *  connections.
         */
        InternalMessageProcessor(RequestQueue* internalQueue,
                                 RemoteRequestManagerHandler* rHandler,
                                 LocalRequestManagerHandler* lHandler,
                                 OutgoingClient* client);

        //! Sets the RequestQueue for requests to be processed.
        /*!
         *  Assigns the specified RequestQueue for processing
         *  requests.
         *  \param internalQueue the RequestQueue to assign.
         */
        void setInternalQueue(RequestQueue* internalQueue);

        //! Sets the RemoteRequestManagerHandler.
        /*!
         *  Sets the RemoteRequestManagerHandler.  It is not invoked
         *  directly, but is contained in the object for management
         *  and method handling.
         *  \param handler the RemoteRequestManagerHandler to assign.
         */
        void setRemoteHandler(RemoteRequestManagerHandler* handler);

        //! Sets the LocalRequestManagerHandler.
        /*!
         *  Sets the LocalRequestManagerHandler.  It is not invoked
         *  directly, but is contained in the object for management
         *  and method handling.
         *  \param handler the LocalRequestManagerHandler to assign.
         */
        void setLocalHandler(LocalRequestManagerHandler* handler);

        //! Sets the OutgoingClient
        /*!
         *  Sets the OutgoingClient.  It is not invoked directly, but
         *  is contained in the object for management and method
         *  handling.
         *  \param client the OutgoingClient to assign.
         */
        void setOutgoingClient(OutgoingClient* client);

        //! Starts processing of internal requests.
        /*!
         *  Intiates a loop that includes processing of all internal
         *  requests to be handled by the InternalMessageProcessor.
         *  The InternalMessageProcessor does not perform any
         *  multi-threading on its own, however, it includes
         *  protections that make it thread safe.  A mutex is used so
         *  that once run() is called, any subsequent calls have no
         *  effect.  RequestQueue notification locks are used for
         *  blocking behavior so that the InternalMessageProcessor
         *  doesn't need to use an explicit wait or sleep to prevent
         *  spinning.  A pthread_mutex_timedlock of 10 seconds is used
         *  so that shutdown commands can break the loop from
         *  processing.  Once started, the InternalMessageProcessor
         *  will run until shutdown() is called.
         */
        void run();
        
        //! Stops processing of internal requests.
        /*!
         *  Sets the flag that indicates that processing should stop.
         *  Due to the architecture of the run() loop, any outstanding
         *  requests will be processed prior to shutting down.
         */
        void shutdown();

        //! Internal method for retrieving a list of servers.
        /*!
         *  Retrieves the list of servers from the client and sends
         *  the response to the specified return service if specified.
         */
        void getServerList(int32_t serviceId);
    private:
        //! Internal only method, executes the specified queueItem.
        void processQueueItem(queueItem* item);
        //! Internal only method, processes any ready queueItems.
        void processReadyQueue();


        
        RequestQueue* _internalQueue;
        RemoteRequestManagerHandler* _remoteHandler;
        LocalRequestManagerHandler* _localHandler;
        OutgoingClient* _client;
        
        /*
         * Mutex lock so we can enter an infinite loop waiting for
         * items to be added to the queue without having it just sit
         * there and spin.
         */
        pthread_mutex_t _queuedItemMutex;
        /*
         * Mutex lock to ensure the InternalMessageProcessor can only
         * be running once.
         */
        pthread_mutex_t _runMutex;
        bool _shutdown;
    };
}

#endif 	    /* !INTERNALMESSAGEPROCESSOR_H_ */
