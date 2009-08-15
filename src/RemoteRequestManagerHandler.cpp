#include "RemoteRequestManagerHandler.h"

using namespace kumonosu;

RemoteRequestManagerHandler::RemoteRequestManagerHandler(RequestQueue *queue)
{
    _incomingRequestQueue = queue;
}

void
RemoteRequestManagerHandler::setRequestQueue(RequestQueue *queue)
{
    _incomingRequestQueue = queue;
}

void
RemoteRequestManagerHandler::QueueItem(const int32_t serviceId, const queueItem& item)
{
    if (_incomingRequestQueue == NULL) {
        return;
    }

    queueItem *_item = new queueItem();
    _item->methodId = item.methodId;
    _item->serverId = item.serverId;
    _item->argList = item.argList;

    _incomingRequestQueue->addItem(serviceId, _item);
}
