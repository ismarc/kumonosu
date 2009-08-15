#include "Callback.h"

using namespace kumonosu;

Callback::Callback(void* object, void(*FunctionPtr)(void* object,
                                                    arguments argList))
{
    _methodObject = object;
    _method = FunctionPtr;
}

void
Callback::execute(arguments argList)
{
    if (_methodObject != NULL &&
        _method != NULL) {
        _method(_methodObject, argList);
    }
}
