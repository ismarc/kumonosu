/*
** MethodMap.h
** 
** Made by Matthew Brace
** Login   <mbrace@godwin.lan>
** 
** Started on  Wed Sep  9 19:18:40 2009 Matthew Brace
** Last update Wed Sep  9 19:18:40 2009 Matthew Brace
*/

#ifndef   	METHODMAP_H_
#define   	METHODMAP_H_

#include "kumonosu_server_types.h"

namespace kumonosu {
    class MethodMap {
    public:
        static const int32_t IMShutdown = 1;
        static const int32_t IMGetServerList = 2;
        static const int32_t IMGetServerResponse = 3;
    private:
        MethodMap();
    };
} // end namespace

#endif 	    /* !METHODMAP_H_ */
