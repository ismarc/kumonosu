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
                // Method id's under 1000 are reserved for internal methods
                static const int32_t PlaceholderMethod = 1000;
            private:
                MethodMap();
            };
            
        public:
            static void methodNotFound(void *object, arguments argList);
            static void getServerListResponse(void *object, arguments argList);
        private:
            MethodHandler();
        };
    }
}

#endif 	    /* !METHODHANDLER_H_ */
