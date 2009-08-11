/*
** Callback.h
** 
** Made by Matthew Brace
** Login   <mbrace@godwin.lan>
** 
** Started on  Mon Aug 10 22:51:33 2009 Matthew Brace
** Last update Mon Aug 10 22:51:33 2009 Matthew Brace
*/

#ifndef   	CALLBACK_H_
#define   	CALLBACK_H_

#include "kumonosu_server_types.h"

namespace kumonosu {
    //! Provides a simple wrapper for callback functions.
    /*!
     *  \class Callback
     *
     *  Callback is a very simple wrapper for managing callback
     *  functions using function pointers.  It provides no explicit
     *  threading protections, instead it is the responsibility of the
     *  callback provider to provide thread safety.
     *
     *  \author Matt Brace
     */
    class Callback {
    public:
        //! Initializes the callback function
        /*!
         *  Assigns the items for internal data storage, used during
         *  execution.
         *  \param object The object that the function is a member of.
         *  \param FunctionPtr The pointer to the function for execution.
         */
        Callback(void* object, void (*FunctionPtr)(void* object,
                                                   arguments argList));
        ~Callback() {}

        //! Executes the stored callback function
        /*!
         *  Executes the stored callback function with the signature:
         *  function(void* object, arguments)
         *  \param argList The arguments object to include in the call
         */
        void execute(arguments argList);
    private:
        //! Stores the object associated with the method
        void* _methodObject;
        //! Stores the function pointer
        void (*_method)(void*, arguments);
    };
}

#endif 	    /* !CALLBACK_H_ */
