#include "LocalRequestManagerHandlerTest.h"
#include "LocalRequestManagerHandler.h"
#include "RequestQueue.h"

using namespace kumonosu;

void
LocalRequestManagerHandlerTest::constructorTest()
{
    RequestQueue* iqueue = new RequestQueue();
    RequestQueue* oqueue = new RequestQueue();
    RequestQueue* lqueue = new RequestQueue();
    LocalRequestManagerHandler* handler = new LocalRequestManagerHandler(iqueue,
                                                                         oqueue,
                                                                         lqueue);
    CPPUNIT_ASSERT(handler != NULL);
}

void
LocalRequestManagerHandlerTest::setIncomingQueueTest()
{
    RequestQueue* iqueue = new RequestQueue();
    RequestQueue* second_queue = new RequestQueue();
    RequestQueue* oqueue = new RequestQueue();
    RequestQueue* lqueue = new RequestQueue();
    LocalRequestManagerHandler* handler = new LocalRequestManagerHandler(iqueue,
                                                                         oqueue,
                                                                         lqueue);
    handler->setIncomingQueue(second_queue);
    CPPUNIT_ASSERT(handler != NULL);
}

void
LocalRequestManagerHandlerTest::setOutgoingQueueTest()
{
    RequestQueue* iqueue = new RequestQueue();
    RequestQueue* oqueue = new RequestQueue();
    RequestQueue* lqueue = new RequestQueue();
    RequestQueue* second_queue = new RequestQueue();
    LocalRequestManagerHandler* handler = new LocalRequestManagerHandler(iqueue,
                                                                         oqueue,
                                                                         lqueue);
    handler->setOutgoingQueue(second_queue);
    CPPUNIT_ASSERT(handler != NULL);
}

void
LocalRequestManagerHandlerTest::setLocalQueueTest()
{
    RequestQueue* iqueue = new RequestQueue();
    RequestQueue* oqueue = new RequestQueue();
    RequestQueue* lqueue = new RequestQueue();
    RequestQueue* second_queue = new RequestQueue();
    LocalRequestManagerHandler* handler = new LocalRequestManagerHandler(iqueue,
                                                                         oqueue,
                                                                         lqueue);
    handler->setLocalQueue(second_queue);
    CPPUNIT_ASSERT(handler != NULL);
}

void
LocalRequestManagerHandlerTest::queueItemTest()
{
    RequestQueue* iqueue = new RequestQueue();
    RequestQueue* oqueue = new RequestQueue();
    RequestQueue* lqueue = new RequestQueue();
    LocalRequestManagerHandler* handler = new LocalRequestManagerHandler(iqueue,
                                                                         oqueue,
                                                                         lqueue);
    int32_t serviceId = 1;
    queueItem item;
    queueItem* resultItem;
    item.methodId = 1;
    handler->QueueItem(serviceId, item);
    resultItem = oqueue->getItem(serviceId);
    CPPUNIT_ASSERT(resultItem->methodId = item.methodId);
}

void
LocalRequestManagerHandlerTest::getItemTest()
{
    RequestQueue* iqueue = new RequestQueue();
    RequestQueue* oqueue = new RequestQueue();
    RequestQueue* lqueue = new RequestQueue();
    LocalRequestManagerHandler* handler = new LocalRequestManagerHandler(iqueue,
                                                                         oqueue,
                                                                         lqueue);
    int32_t serviceId = 1;
    queueItem first_item;
    queueItem second_item;
    queueItem resultItem;

    first_item.methodId = 1;
    second_item.methodId = 2;
    iqueue->addItem(serviceId, &first_item);
    iqueue->addItem(2, &second_item);
    handler->GetItem(resultItem, serviceId);
    CPPUNIT_ASSERT(resultItem.methodId == first_item.methodId);
}

void
LocalRequestManagerHandlerTest::getItemListTest()
{
    RequestQueue* iqueue = new RequestQueue();
    RequestQueue* oqueue = new RequestQueue();
    RequestQueue* lqueue = new RequestQueue();
    LocalRequestManagerHandler* handler = new LocalRequestManagerHandler(iqueue,
                                                                         oqueue,
                                                                         lqueue);
    int32_t serviceId = 1;
    queueItem first_item;
    queueItem second_item;
    queueItem third_item;
    queueItemList resultList;

    first_item.methodId = 1;
    second_item.methodId = 2;
    third_item.methodId = 3;
    iqueue->addItem(serviceId, &first_item);
    iqueue->addItem(serviceId, &second_item);
    iqueue->addItem(2, &third_item);

    handler->GetItemList(resultList, serviceId);
    CPPUNIT_ASSERT(resultList.items.size() == 2);
    CPPUNIT_ASSERT(resultList.items[0].methodId == first_item.methodId);
    CPPUNIT_ASSERT(resultList.items[1].methodId == second_item.methodId);
}

void
LocalRequestManagerHandlerTest::getItemListByCountTest()
{
    RequestQueue* iqueue = new RequestQueue();
    RequestQueue* oqueue = new RequestQueue();
    RequestQueue* lqueue = new RequestQueue();
    LocalRequestManagerHandler* handler = new LocalRequestManagerHandler(iqueue,
                                                                         oqueue,
                                                                         lqueue);
    int32_t serviceId = 1;
    queueItem first_item;
    queueItem second_item;
    queueItem third_item;
    queueItemList resultList;

    first_item.methodId = 1;
    second_item.methodId = 2;
    third_item.methodId = 3;
    iqueue->addItem(serviceId, &first_item);
    iqueue->addItem(serviceId, &second_item);
    iqueue->addItem(2, &third_item);

    handler->GetItemListByCount(resultList, serviceId, 1);
    CPPUNIT_ASSERT(resultList.items.size() == 1);
    CPPUNIT_ASSERT(resultList.items[0].methodId == first_item.methodId);
}
