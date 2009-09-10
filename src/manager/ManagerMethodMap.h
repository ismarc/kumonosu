/*
** ManagerMethodMap.h
** 
** Made by Matthew Brace
** Login   <mbrace@godwin.lan>
** 
** Started on  Wed Sep  9 19:19:08 2009 Matthew Brace
** Last update Wed Sep  9 19:19:08 2009 Matthew Brace
*/

#ifndef   	MANAGERMETHODMAP_H_
#define   	MANAGERMETHODMAP_H_

#include "clientlib/MethodMap.h"

#include "kumonosu_server_types.h"

namespace kumonosu {
    namespace manager {
        class ManagerMethodMap : public MethodMap {
        public:
            // IDs under 1000 are reserved
            static const int32_t Ping = 1000;
            static const int32_t Pong = 1001;
            static const int32_t GetServiceList = 1002;
            static const int32_t GetServiceListResponse = 1003;
        private:
            ManagerMethodMap();
        };
    } // end namespace
} // end namespace

#endif 	    /* !MANAGERMETHODMAP_H_ */
