#include "LocalRequestManagerHandler.h"

using namespace kumonosu;

LocalRequestManagerHandler::LocalRequestManagerHandler(RequestQueue *incoming_queue,
                                                       RequestQueue *outgoing_queue,
                                                       RequestQueue *local_queue)
{
    _incomingRequestQueue = incoming_queue;
    _outgoingRequestQueue = outgoing_queue;
    _localRequestQueue = local_queue;
}

void
LocalRequestManagerHandler::QueueItem(const int32_t serviceId,
                                      const queueItem& item)
{
    queueItem* _item = new queueItem();

    if (_outgoingRequestQueue != NULL) {
        _item->methodId = item.methodId;
        _item->serverId = item.serverId;
        _item->argList = item.argList;
        _outgoingRequestQueue->addItem(serviceId, _item);
    }
}

void
LocalRequestManagerHandler::QueueInternalItem(const queueItem& item)
{
    queueItem* _item = new queueItem();
    if (_localRequestQueue != NULL) {
        _item->methodId = item.methodId;
        _item->serverId = item.serverId;
        _item->argList = item.argList;
        _localRequestQueue->addItem(0, _item);
    }
}

void
LocalRequestManagerHandler::GetItem(queueItem& _return, const int32_t serviceId)
{
    if (_incomingRequestQueue == NULL) {
        return;
    }

    queueItem* item = _incomingRequestQueue->getItem(serviceId);

    if (item != NULL) {
        _return.methodId = item->methodId;
        _return.serverId = item->serverId;
        _return.argList = item->argList;
    }
}

void
LocalRequestManagerHandler::GetItemList(queueItemList& _return,
                                        const int32_t serviceId)
{
    if (_incomingRequestQueue == NULL) {
        return;
    }

    std::queue<queueItem*> itemQueue = _incomingRequestQueue->getItemQueue(serviceId);

    while (!itemQueue.empty() &&
           itemQueue.front() != NULL) {
        queueItem item;
        item.methodId = itemQueue.front()->methodId;
        item.serverId = itemQueue.front()->serverId;
        item.argList = itemQueue.front()->argList;
        _return.items.push_back(item);
        itemQueue.pop();
    }
}

void
LocalRequestManagerHandler::GetItemListByCount(queueItemList& _return,
                                               const int32_t serviceId,
                                               const int32_t count)
{
    if (_incomingRequestQueue == NULL) {
        return;
    }

    std::queue<queueItem*> itemQueue = _incomingRequestQueue->getItemQueue(serviceId, count);

    while (!itemQueue.empty() &&
           itemQueue.front() != NULL) {
        queueItem item;
        item.methodId = itemQueue.front()->methodId;
        item.serverId = itemQueue.front()->serverId;
        item.argList = itemQueue.front()->argList;
        _return.items.push_back(item);
        itemQueue.pop();
    }
}

void
LocalRequestManagerHandler::setIncomingQueue(RequestQueue *queue)
{
    _incomingRequestQueue = queue;
}

void
LocalRequestManagerHandler::setOutgoingQueue(RequestQueue *queue)
{
    _outgoingRequestQueue = queue;
}

void
LocalRequestManagerHandler::setLocalQueue(RequestQueue *queue)
{
    _localRequestQueue = queue;
}
