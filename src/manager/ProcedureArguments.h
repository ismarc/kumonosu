/*
** ProcedureArguments.h
** 
** Made by Matthew Brace
** Login   <mbrace@godwin.lan>
** 
** Started on  Sat Sep  5 21:27:02 2009 Matthew Brace
** Last update Sat Sep  5 21:27:02 2009 Matthew Brace
*/

#ifndef   	PROCEDUREARGUMENTS_H_
#define   	PROCEDUREARGUMENTS_H_

#include "kumonosu_server_types.h"

namespace kumonosu {
    namespace manager {
        //! Abstract base class for classes for serializing arguments.
        /*!
         *  \class ProcedureArguments
         *
         *  The current model doesn't use this very well.  It needs to
         *  be rethought out to provide a reasonable interface to take
         *  advantage of the potential features.
         *
         *  \author Matt Brace
         */
        class ProcedureArguments {
        public:
            ProcedureArguments();
            virtual ~ProcedureArguments();

            virtual void addToArguments(arguments* args) = 0;
            virtual void loadFromArguments(arguments args) = 0;
        };
    }
}

#endif 	    /* !PROCEDUREARGUMENTS_H_ */
