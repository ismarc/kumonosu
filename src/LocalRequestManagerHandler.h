/*
** LocalRequestManagerHandler.h
** 
** Made by Matthew Brace
** Login   <mbrace@godwin.lan>
** 
** Started on  Mon Jul 27 22:35:42 CDT 2009 Matthew Brace
** Last update Sun Aug  2 17:09:11 CDT 2009 Matthew Brace
*/

#ifndef   	LOCALREQUESTMANAGERHANDLER_H_
#define   	LOCALREQUESTMANAGERHANDLER_H_

#include "LocalRequestManager.h"
#include "RequestQueue.h"
#include "kumonosu_server_types.h"

namespace kumonosu {
    //! Provides the manager interface for internal originating requests.
    /*!
     *  Processes incoming requests from the local server as defined
     *  by the RPC architecture defined by the Thrift generated
     *  interface.  Handles adding items to the proper assigned
     *  RequestQueue.
     *
     *  \author Matt Brace  
     */
    class LocalRequestManagerHandler : virtual public LocalRequestManagerIf {
    public:
        //! Initializes internal data objects and assigns the queues.
        /*!
         *  Associates the supplied queues for sending requests and
         *  retrieving data objects.
         *  \param incoming_queue RequestQueue object for incoming
         *  requests.
         *  \param outgoing_queue RequestQueue object for outgoing
         *  requests.
         *  \param local_queue RequestQueue object for requests
         *  to be processed by the local system.
         */
        LocalRequestManagerHandler(RequestQueue *incoming_queue,
                                   RequestQueue *outgoing_queue,
                                   RequestQueue *local_queue);

        //! RPC interface for queueing items from internal calls.
        /*!
         *  Adds the specified item to the outgoing request queue
         *  using the supplied service id.
         *  \param serviceId a 32 bit integer indicating the service
         *  to associate the item with.
         *  \param item the queueItem to add to the RequestQueue.
         */
        void QueueItem(const int32_t serviceId, const queueItem& item);

        //! RPC interface for queueing items for the local server.
        /*!
         *  Adds the specified item to the local request queue.
         *  \param item The queue item to add to the local request queue.
         */
        void QueueInternalItem(const queueItem& item);

        //! RPC interface for retrieving an item for local calls.
        /*!
         *  Retrieves a single queue item from the incoming queue for
         *  the supplied service id.
         *  \param _return a reference to a queueItem to assign the
         *  item to retrieve.
         *  \param serviceId a 32 bit integer indicating the service
         *  to retrieve an item for.
         */
        void GetItem(queueItem& _return, const int32_t serviceId);

        //! RPC interface for retrieving a list of items for local calls.
        /*!
         *  Retrieves a queueItemList from the incoming queue for the
         *  supplied service id.
         *  \param _return a reference to a queueItemList to assign
         *  the list.
         *  \param serviceId a 32 bit integer indicating the service
         *  to retrieve the list for.
         */
        void GetItemList(queueItemList& _return, const int32_t serviceId);

        //! RPC interface for retrieving a list of items for local calls.
        /*!
         *  Retrieves a queueItemList from the incoming queue for the
         *  supplied service id with a maximum of count entries.
         *  \param _return a reference to a queueItemList to assign
         *  the list.
         *  \param serviceId a 32 bit integer indicating the service
         *  to retrieve the list for.
         *  \param count a 32 bit integer indicating the maximum
         *  number of items to include in the queueItemList.
         */
        void GetItemListByCount(queueItemList& _return,
                                const int32_t serviceId,
                                const int32_t count);

        //! Assigns a new RequestQueue object for the incoming queue.
        /*!
         *  Assigns a new RequestQueue object to the handler for
         *  incoming requests.
         */
        void setIncomingQueue(RequestQueue *queue);

        //! Assigns a new RequestQueue object for the outgoing queue.
        /*!
         *  Assigns a new RequestQueue object to the handler for
         *  outgoing requests.
         */
        void setOutgoingQueue(RequestQueue *queue);

        //! Assigns a new RequestQueue object for the local request queue.
        /*!
         *  Assigns a new RequestQueue object to the handler for local requests.
         */
        void setLocalQueue(RequestQueue *queue);
    private:
        RequestQueue* _incomingRequestQueue;
        RequestQueue* _outgoingRequestQueue;
        RequestQueue* _localRequestQueue;
    };
    
} /* End of namespace kumonosu */

#endif 	    /* !LOCALREQUESTMANAGERHANDLER_H_ */
