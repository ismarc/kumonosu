/*
** ping_arguments.h
** 
** Made by Matthew Brace
** Login   <mbrace@godwin.lan>
** 
** Started on  Sun Sep 13 16:59:34 2009 Matthew Brace
** Last update Sun Sep 13 16:59:34 2009 Matthew Brace
*/

#ifndef   	PING_ARGUMENTS_H_
#define   	PING_ARGUMENTS_H_

#include "kumonosu_server_types.h"

namespace kumonosu {
    namespace manager {
        class ping_arguments : public arguments {
        public:
            /** Default constructor */
            ping_arguments() {}
            /** Cast from arguments constructor.
             *  Facilitates casting an arguments object to
             *  ping_arguments in assignment to populate the
             *  appropriate internal data.
             *  \param arguments the arguments to populate the object from.
             */
            ping_arguments(arguments rhs);
            /** Populate internal arguments data based on supplied items.
             *  Populates the internal data appropriately so that the
             *  ping_arguments object can be cast into an arguments
             *  object for transmission.
             *  \param serverAddress the address of the server to add
             *  \param serverPort the port of the server to add
             *  \param serverId the id of the server to add
             *  \param serviceId the service id of the server to add
             *  \param pingId the id of this ping item to add
             */
            ping_arguments(std::string serverAddress,
                           int32_t serverPort,
                           int32_t serverId,
                           int32_t serviceId,
                           int32_t pingId);
            /** Default destructor */
            ~ping_arguments() throw() {}

            /** Retrieves the internal stored server address
             *  Retrieves the server address as parsed from the
             *  arguments or loaded by the constructor.
             *  \returns the server address contained in the arguments object.
             */
            std::string getServerAddress();
            /** Retrieves the internal stored server port
             *  Retrieves the server port as parsed from the arguments
             *  or loaded by the constructor.
             *  \returns the server port contained in the arguments object.
             */
            int32_t getServerPort();
            /** Retrieves the internal stored ping id
             *  Retrieves the ping id as parsed from the arguments or
             *  loaded by the constructor.
             *  \returns the ping id contained in the arguments object.
             */
            int32_t getPingId();
            /** Retrieves the internal stored service id
             *  Retrieves the service id as parsed from the arguments
             *  or loaded by the constructor.
             *  \returns the service id contained in the arguments object.
             */
            int32_t getServiceId();
            /** Retrieves the internal stored server id
             *  Retrieves the server id as parsed from the arguments
             *  or loaded by the constructor.
             *  \returns the server id contained in the arguments object.
             */
            int32_t getServerId();
        private:
            /** Internal use only, populates the arguments data */
            void generateArguments();
            /** Internal use only, populates from arguments data */
            void loadFromArguments();
            
            std::string _serverAddress;
            int32_t _serverPort;
            int32_t _pingId;
            int32_t _serviceId;
            int32_t _serverId;
        };
    }
}

#endif 	    /* !PING_ARGUMENTS_H_ */
