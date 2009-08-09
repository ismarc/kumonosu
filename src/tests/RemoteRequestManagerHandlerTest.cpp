#include "RemoteRequestManagerHandlerTest.h"
#include "RemoteRequestManagerHandler.h"
#include "RequestQueue.h"

using namespace kumonosu;

void
RemoteRequestManagerHandlerTest::constructorTest()
{
    RequestQueue* queue = new RequestQueue();
    RemoteRequestManagerHandler* handler = new RemoteRequestManagerHandler(queue);

    CPPUNIT_ASSERT(handler != NULL);
}

void
RemoteRequestManagerHandlerTest::setRequestQueueTest()
{
    RequestQueue* first_queue = new RequestQueue();
    RequestQueue* second_queue = new RequestQueue();
    RemoteRequestManagerHandler* handler = new RemoteRequestManagerHandler(first_queue);
    handler->setRequestQueue(second_queue);
    CPPUNIT_ASSERT(handler != NULL);
}

void
RemoteRequestManagerHandlerTest::queueItemTest()
{
    RequestQueue* queue = new RequestQueue();
    RemoteRequestManagerHandler* handler = new RemoteRequestManagerHandler(queue);
    int32_t serviceId = 1;
    queueItem item;
    queueItem* resultItem;
    item.methodId = 1;
    handler->QueueItem(serviceId, item);
    resultItem = queue->getItem(serviceId);
    CPPUNIT_ASSERT(resultItem->methodId == item.methodId);
}
