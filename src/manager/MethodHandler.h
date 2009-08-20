/*
** MethodHandler.h
** 
** Made by Matthew Brace
** Login   <mbrace@godwin.lan>
** 
** Started on  Sun Aug 16 18:25:05 2009 Matthew Brace
** Last update Sun Aug 16 18:25:05 2009 Matthew Brace
*/

#ifndef   	METHODHANDLER_H_
#define   	METHODHANDLER_H_

#include "kumonosu_server_types.h"
#include "internal_method_map.h"

namespace kumonosu {
    namespace manager {
        class MethodHandler {
        public:
            class MethodMap {
            public:
                // Define the internal method values we use
                static const int32_t GetServerList =
                    INTERNAL_METHOD_GET_SERVER_LIST;
                static const int32_t GetServerResponse =
                    INTERNAL_METHOD_GET_SERVER_RESPONSE;
                // Method id's under 1000 are reserved for internal methods
                static const int32_t Ping = 1000;
                static const int32_t Pong = 1001;
                static const int32_t GetServiceList = 1002;
                static const int32_t GetServiceListResponse = 1003;
            private:
                MethodMap();
            };
            
        public:
            static void methodNotFound(void *object, arguments argList);
            static void ping(void *object, arguments argList);
            static void pong(void *object, arguments argList);
            static void getServerList(void *object, arguments argList);
            static void getServerListResponse(void *object, arguments argList);
            static void getServiceList(void *object, arguments argList);
            static void getServiceListResponse(void *object, arguments argList);
        private:
            MethodHandler();
        };
    }
}

#endif 	    /* !METHODHANDLER_H_ */
