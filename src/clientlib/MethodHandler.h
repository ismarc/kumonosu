/*
** MethodHandler.h
** 
** Made by Matthew Brace
** Login   <mbrace@godwin.lan>
** 
** Started on  Sun Sep  6 22:28:01 2009 Matthew Brace
** Last update Sun Sep  6 22:28:01 2009 Matthew Brace
*/

#ifndef   	METHODHANDLER_H_
#define   	METHODHANDLER_H_

#include "kumonosu_server_types.h"

#define CALL_MEMBER_FN(object, ptrToMemFn) ((object)->*(ptrToMemFn))

namespace kumonosu {
    //! Provides a templated system for managing callbacks at run-time
    /*!
     *  \class MethodHandler
     *
     *  MethodHandler provides a templated interface for managing
     *  callbacks to handle methods indexed by id.  This greatly
     *  simplifies the logic necessary in the MessageProcessor and
     *  class that implements the callback functions.  The class
     *  stores a map of method id to member function of the associated
     *  object.
     *  
     *  \author Matt Brace
     */
    template <class T>
    class MethodHandler {
        typedef void (T::*CallbackFn)(arguments argList);
    public:
        //! Constructor, uses the provided object for all callbacks.
        /*!
         *  \param object the object to use for callbacks associated
         *  with the MethodHandler.
         */
        MethodHandler(T* object) : _object(object) {}
        
        ~MethodHandler() {}

        //! Adds a function pointer to the call map.
        /*!
         *  Assigns the supplied function pointer to the associated
         *  method id.  For method ids that have not been assigned,
         *  the function pointer associated with method not found is
         *  called.
         *  \see addMethodNotFound
         *  \param methodId the index to associate with the function.
         *  \param function the function pointer to call when the
         *  appropriate method id should be invoked.
         */
        void addMethod(int32_t methodId, CallbackFn function) {
            typename std::map<int32_t, CallbackFn>::iterator it =
                _methodMap.find(methodId);

            if (it != _methodMap.end()) {
                _methodMap.erase(it);
            }

            _methodMap.insert(std::pair<int32_t, CallbackFn>(methodId, function));
        }
        
        //! Adds a function pointer to call when a method is not found.
        /*!
         *  The function pointed to by the supplied pointer is invoked
         *  whenever a method id is supplied that doesn't have an
         *  associated function pointer.
         *  \param function the function to invoke.
         */
        void addMethodNotFound(CallbackFn function) {
            _methodNotFound = function;
        }
        
        //! Removes a function pointer for the associated method id.
        /*!
         *  The function pointer associated with the supplied method
         *  id is removed from the map if it was set.
         *  \param methodId the id of the method to remove.
         */
        void removeMethod(int32_t methodId) {
            typename std::map<int32_t, CallbackFn>::iterator it =
                _methodMap.find(methodId);
            if (it== _methodMap.end()) {
                _methodMap.erase(it);
            }
        }
        
        //! Executes the function associated with the method id.
        /*!
         *  The function associated with the method id is executed if
         *  it exists.  The method not found function is executed if
         *  there is no associated function with the method id.
         *  \param methodId the id of the function to execute.
         *  \param args the arguments to call the function with.
         */
        void executeMethod(int32_t methodId, arguments args) {
            CallbackFn method;

            if (_methodMap.find(methodId) != _methodMap.end()) {
                method = _methodMap.find(methodId)->second;
            } else {
                method = _methodNotFound;
            }

            CALL_MEMBER_FN(_object, method)(args);
        }
    private:
        CallbackFn _methodNotFound;
        std::map<int32_t, CallbackFn> _methodMap;
        T* _object;
    };
}

#endif 	    /* !METHODHANDLER_H_ */
