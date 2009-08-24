#include "MessageProcessor.h"

using namespace kumonosu;

MessageProcessor::MessageProcessor(void* methodNotImplementedObject,
                                   void (*methodNotImplemented)
                                   (void* object,
                                    arguments argList)) :
    _methodNotImplemented(methodNotImplementedObject,
                          methodNotImplemented)
{

}

void
MessageProcessor::setClient(Client* client)
{
    _client = client;
}

void
MessageProcessor::setMethodCallback(int32_t methodId,
                                    void* object,
                                    void (*FunctionPtr)(void* object,
                                                        arguments argList))
{
    Callback methodCallback(object, FunctionPtr);
    _callbackMap.insert(std::pair<int32_t, Callback>
                        (methodId, methodCallback));
}

void
MessageProcessor::removeMethodCallback(int32_t methodId)
{
    _callbackMap.erase(methodId);
}

void
MessageProcessor::executeMethod(int32_t methodId,
                                arguments argList)
{
    std::map<int32_t, Callback>::iterator it;

    it = _callbackMap.find(methodId);

    if (it != _callbackMap.end()) {
        it->second.execute(argList);
    } else {
        i32Arg method;
        method.name = "methodId";
        method.value = methodId;
        
        argList.i32Args.push_back(method);
        _methodNotImplemented.execute(argList);
    }
}

void
MessageProcessor::processPendingItems(int32_t max_count = -1)
{
    queueItemList pending_items;

    if (_client == NULL) {
        return;
    }

    try {
        _client->connect();
    } catch (TTransportException e) {
        // This is similar to NULL, client can't connect
        return;
    }

    if (max_count == -1) {
        pending_items = _client->getPendingItems();
    } else {
        pending_items = _client->getPendingItems(max_count);
    }

    for (std::vector<queueItem>::iterator it = pending_items.items.begin();
         it != pending_items.items.end();
         it++) {
        executeMethod((*it).methodId, (*it).argList);
    }
}
