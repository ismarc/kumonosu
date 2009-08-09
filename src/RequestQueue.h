/*
** RequestQueue.h
** 
** Made by Matthew Brace
** Login   <mbrace@godwin.lan>
** 
** Started on  Fri Jul 31 01:03:53 CDT 2009 Matthew Brace
** Last update Sun Aug  2 16:39:10 CDT 2009 Matthew Brace
*/

#ifndef   	REQUESTQUEUE_H_
#define   	REQUESTQUEUE_H_

#include "kumonosu_server_types.h"

#include <queue>
#include <map>
#include <vector>
#include <pthread.h>

namespace kumonosu {
    //! Provides management of std::queue's for multiple destination services.
    /*!
     *  \class RequestQueue
     *  
     *  RequestQueue is designed to provide a queue of items destined
     *  for multiple consumers.  It is an aggregation of queues for
     *  each service.  It is not designed to replace std::queue, instead it is a
     *  container for multiple std::queue's.  It is organized by
     *  service id and allows multiple methods of accessing the items
     *  in the queues.  To ease use, the internal storage will not
     *  contain entries for empty queues.
     *  The system will dynamically add and remove entries based on
     *  adding and removing items.  The idea is that a call to
     *  getServiceIds will retrieve a list of all service ids with items in a 
     *  queue.  The goal is to have no additional overhead on the
     *  caller, just add or get items and the right thing is done.
     *  
     *  \author Matt Brace
     *
     */
    class RequestQueue {
    public:
        //! Initializes internal data objects.
        RequestQueue();
        
        //! Adds an item to the end of the queue for the service id.
        /*!
         *  Adds an item to the queue associated with the supplied
         *  service id.  If a queue did not originally exist, one is
         *  created.
         *  \param serviceId a 32 bit integer indicating the id of the
         *  associated service.
         *  \param item a pointer to a queueItem object to be added to
         *  the queue.
         */
        void addItem(int32_t serviceId, queueItem *item);

        //! Retrieves the next item in the specified queue.
        /*!
         *  Returns an appropriate queueItem or null if one does not
         *  exist.
         *  \param serviceId a 32 bit integer indicating the id of the
         *  service to retrieve the item from.
         *  \return the next queueItem in the queue or NULL
         */
        queueItem* getItem(int32_t serviceId);

        //! Retrieves the entire queue for the associated service id.
        /*! 
         *  Retrieves the entire associated queue for the supplied
         *  service id or an empty queue if there are no items.
         *  \param serviceId a 32 bit integer indiciating the id of
         *  service to retrieve the queue for.
         *  \return a std::queue for the specified service id or an
         *  empty queue if there are no associated items.
         */
        std::queue<queueItem*> getItemQueue(int32_t serviceId);

        //! Retrieves a queue with n items for the service id.
        /*!
         *  Retrieves the queue for the specified service id, with a
         *  maximum number of items as specified by count.
         *  \param serviceId a 32 bit integer indicating the id of the
         *  service to retrieve the queue for.
         *  \param count a 32 bit integer indicating the maximum
         *  number of items to include in the return item.
         *  \return a std::queue for the specified service id with a
         *  maximum of count items, or an empty queue if there are no
         *  associated items.
         */
        std::queue<queueItem*> getItemQueue(int32_t serviceId, int32_t count);

        //! Retrieves the list of service ids with items in a queue.
        /*!
         *  Retrieves the list of service ids that have items in their
         *  queue, suitable for a global consumer to determine what
         *  needs to be requested.
         *  \return a std::vector of service ids.
         */
        std::vector<int32_t> getServiceIds();

        //! Assigns a mutex for use in notifications of new items in a queue.
        /*!
         *  The given mutex is locked when supplied.  The mutex is
         *  unlocked when items are added to any queue.  Suitable for
         *  providing blocking behavior waiting for items to be added
         *  to the queue.  When the mutex is unlocked, it is removed
         *  from the list and must be added again when notification is
         *  needed.  This allows external and containing objects time
         *  to process items before reestablishing notification.
         *  \param mutex The mutex to be locked initially and unlocked
         *  for notification.
         */
        void queueLock(pthread_mutex_t* mutex);
    private:
        /** 
         *  Map of service id's to std::queue's
         */
        std::map<int32_t, std::queue<queueItem*> > _requestMap;
        /** 
         *  Provides locking for the internal storage to support concurrency
         */
        pthread_mutex_t _dataStoreMutex;

        std::vector<pthread_mutex_t*> _itemAddedMutexList;
    };
} /* End of namespace kumonosu */

#endif 	    /* !REQUESTQUEUE_H_ */
