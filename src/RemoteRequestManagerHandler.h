/*
** RemoteRequestManagerHandler.h
** 
** Made by Matthew Brace
** Login   <mbrace@godwin.lan>
** 
** Started on  Mon Jul 27 22:29:12 CDT 2009 Matthew Brace
** Last update Sun Aug  2 17:01:04 CDT 2009 Matthew Brace
*/

#ifndef   	REMOTEREQUESTMANAGERHANDLER_H_
#define   	REMOTEREQUESTMANAGERHANDLER_H_

#include "RemoteRequestManager.h"
#include "RequestQueue.h"
#include "kumonosu_server_types.h"

namespace kumonosu {
    //! Provides the manager interface for external originating requests.
    /*!
     *  Processes incoming requests as defined by the RPC architecture
     *  defined by the Thrift generated interface.  Handles adding
     *  items to the assigned RequestQueue.
     *
     *  \author Matt Brace
     */
    class RemoteRequestManagerHandler : virtual public RemoteRequestManagerIf {
    public:
        //! Initializes internal data objects and assigns the queue.
        /*!
         *  Associates the supplied queue with incoming requests for
         *  queuing.
         *  \param queue the RequestQueue to add incoming requests
         */
        RemoteRequestManagerHandler(RequestQueue *queue);

        //! Assigns a new RequestQueue object.
        /*!
         *  Assigns a new RequestQueue object to the handler for
         *  queuing incoming requests.
         */
        void setRequestQueue(RequestQueue *queue);

        //! RPC interface for queueing items from external calls.
        /*!
         *  Adds the specified item to the associated request queue
         *  using the supplied service id.
         *  \param serviceId a 32 bit integer indicating the service
         *  to associate the item with.
         *  \param item the queueItem to add to the RequestQueue.
         */
        void QueueItem(const int32_t serviceId, const queueItem& item);

    private:
        RequestQueue* _incomingRequestQueue;
    };
} /* End of namespace kumonosu */


#endif 	    /* !REMOTEREQUESTMANAGERHANDLER_H_ */
