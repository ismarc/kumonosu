/*
** MessageProcessor.h
** 
** Made by Matthew Brace
** Login   <mbrace@godwin.lan>
** 
** Started on  Mon Aug 10 01:55:16 CDT 2009 Matthew Brace
** Last update Mon Aug 10 22:22:49 CDT 2009 Matthew Brace
*/

#ifndef   	MESSAGEPROCESSOR_H_
#define   	MESSAGEPROCESSOR_H_

#include "kumonosu_server_types.h"
#include "clientlib/Client.h"
#include "clientlib/MethodHandler.h"
#include "Callback.h"

namespace kumonosu {
    template <class T>
    class MethodHandler;

    //! Provides a convenience interface for managing pending items.
    /*!
     *  \class MessageProcessor
     *
     *  The message processor provides a convenience class for
     *  handling incoming queue items.  A class (or classes) can be
     *  created to handle the different methods which are then
     *  provided to the message processor as callbacks.  The service
     *  can then call the MessageProcessor to execute any outstanding
     *  items.
     *
     *  \author Matt Brace
     */
    template <class T>
    class MessageProcessor {
    public:
        typedef void (T::*CallbackFn)(arguments argList);
        //! Initializes the MessageProcessor
        /*!
         *  The constructor takes an object pointer and a function
         *  pointer for the callback that is called whenever a method
         *  callback has not been set for the received method id.
         *  \param methodNotImplementedObject the object to supply in
         *  the callback when a request for an undefined method is
         *  received.
         *  \param methodNotImplemented function pointer to the method
         *  to call when an undefined method is received.
         */
        MessageProcessor(T* object,
                         CallbackFn methodNotImplemented) :
            _callbackObject(object),
            _handler(_callbackObject)
        {
            _handler.addMethodNotFound(methodNotImplemented);
        }

        ~MessageProcessor() {}

        //! Assigns the supplied client
        /*!
         *  To retreive requests, a client is necessary.  It is the
         *  owning objects responsibility to initialize and supply the
         *  client.  Once received, the MessageProcessor will have the
         *  client connect if necessary for further calls, but will
         *  never explicitly disconnect the client.
         *  \param client the client object to use for message retrieval.
         */
        void setClient(Client* client) {
            _client = client;
        }

        //! Stores a callback function associated with a method id.
        /*!
         *  Creates a Callback object and associates it internally
         *  with the supplied method id.  The callback will be called
         *  with there is an incoming request with the specified
         *  method id.
         *  \param methodId the method id to associate the callback
         *  with.
         *  \param object the object to call with the function pointer
         *  \param FunctionPtr the function pointer for the callback.
         */
        void setMethodCallback(int32_t methodId,
                               CallbackFn function) {
            _handler.addMethod(methodId, function);
        }

        //! Removes a Callback object from the method associations.
        /*!
         *  Removes the Callback object that is associated with the
         *  method id.  If further requests are processed with that
         *  method id, the methodNotImplemented callback will be used
         *  until a new callback has been set.
         *  \param methodId the method id of the callback to remove.
         */
        void removeMethodCallback(int32_t methodId) {
            _handler.removeMethod(methodId);
        }

        //! Processes outstanding items.
        /*!
         *  Retrieves up to max_count items and calls the associated
         *  callback method with the received method id for each
         *  item.  The callbacks are called serially, in the order
         *  they are received based on the queue.
         *  \param max_count the maximum number of items to process,
         *  use -1 to indicate all items.
         */
        void processPendingItems(int32_t max_count) {
            queueItemList pending_items;

            if (_client == NULL) {
                return;
            }

            try {
                _client->connect();
            } catch (TTransportException e) {
                // This is similar to NULL, client can't connect;
                return;
            }

            if (max_count == -1) {
                pending_items = _client->getPendingItems();
            } else {
                pending_items = _client->getPendingItems(max_count);
            }

            for (std::vector<queueItem>::iterator it =
                     pending_items.items.begin();
                 it != pending_items.items.end();
                 it++) {
                _handler.executeMethod((*it).methodId, (*it).argList);
            }
        }

    private:
        T* _callbackObject;
        Client* _client;
        MethodHandler<T> _handler;
    };
}

#endif 	    /* !MESSAGEPROCESSOR_H_ */
