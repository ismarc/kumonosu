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
#include "Client.h"
#include "Callback.h"

namespace kumonosu {
    class MessageProcessor {
    public:
        // Should really typedef this to look better
        MessageProcessor(void* methodNotImplementedObject,
                         void (*methodNotImplemented)(void* object,
                                                      arguments argList));
        ~MessageProcessor() {};

        void setClient(Client* client);
        void setMethodCallback(int32_t methodId, void* object,
                               void(*FunctionPtr)
                               (void* object,
                                arguments argList));
        void removeMethodCallback(int32_t methodId);
        void processPendingItems(int32_t max_count);
    private:
        void executeMethod(int32_t methodId, arguments argList);

        Client* _client;
        Callback _methodNotImplemented;
        std::map<int32_t, Callback> _callbackMap;
    };
}

#endif 	    /* !MESSAGEPROCESSOR_H_ */
