#include "RequestQueueTest.h"
#include "RequestQueue.h"
#include <pthread.h>

using namespace kumonosu;

void
RequestQueueTest::constructorTest()
{
    RequestQueue* queue = new RequestQueue();
    CPPUNIT_ASSERT(queue != NULL);
}

void
RequestQueueTest::addItemTest()
{
    RequestQueue* queue = new RequestQueue();
    int32_t serviceId = 1;
    queueItem item;
    item.methodId = 0;
    queue->addItem(serviceId, &item);
}

void
RequestQueueTest::getItemTest()
{
    RequestQueue* queue = new RequestQueue();
    int32_t serviceId = 1;
    queueItem item;
    queueItem* resultItem;
    item.methodId = 0;
    queue->addItem(serviceId, &item);

    resultItem = queue->getItem(serviceId);
    CPPUNIT_ASSERT(resultItem->methodId == item.methodId);
}

void
RequestQueueTest::getItemEmptyTest()
{
    RequestQueue* queue = new RequestQueue();
    int32_t serviceId = 1;
    queueItem item;
    queueItem* resultItem;
    queueItem* resultItemTwo;
    
    item.methodId = 0;
    queue->addItem(serviceId, &item);

    resultItem = queue->getItem(serviceId);

    resultItemTwo = queue->getItem(serviceId);

    CPPUNIT_ASSERT(resultItemTwo == NULL);
}

void
RequestQueueTest::getItemQueueTest()
{
    RequestQueue* queue = new RequestQueue();
    int32_t serviceId = 1;
    queueItem first_item;
    queueItem second_item;
    queueItem third_item;
    
    first_item.methodId = 0;
    second_item.methodId = 1;
    third_item.methodId = 2;

    queue->addItem(serviceId, &first_item);
    queue->addItem(serviceId, &second_item);
    queue->addItem(2, &third_item);

    std::queue<queueItem*> itemList = queue->getItemQueue(serviceId);
    CPPUNIT_ASSERT(itemList.size() == 2);
}

void
RequestQueueTest::getItemQueueByCountTest()
{
    RequestQueue* queue = new RequestQueue();
    int32_t serviceId = 1;
    queueItem first_item;
    queueItem second_item;
    queueItem third_item;
    
    first_item.methodId = 0;
    second_item.methodId = 1;
    third_item.methodId = 2;

    queue->addItem(serviceId, &first_item);
    queue->addItem(serviceId, &second_item);
    queue->addItem(2, &third_item);

    std::queue<queueItem*> itemList = queue->getItemQueue(serviceId, 1);
    CPPUNIT_ASSERT(itemList.size() == 1);
}

void
RequestQueueTest::getServiceIdsTest()
{
    RequestQueue* queue = new RequestQueue();
    int32_t serviceId = 1;
    queueItem first_item;
    queueItem second_item;
    queueItem third_item;
    
    first_item.methodId = 0;
    second_item.methodId = 1;
    third_item.methodId = 2;

    queue->addItem(serviceId, &first_item);
    queue->addItem(serviceId, &second_item);
    queue->addItem(2, &third_item);

    std::vector<int32_t> idList = queue->getServiceIds();
    CPPUNIT_ASSERT(idList.size() == 2);
    CPPUNIT_ASSERT(idList[0] == serviceId);
    CPPUNIT_ASSERT(idList[1] == 2);
}

void
RequestQueueTest::queueLockTest()
{
    RequestQueue* queue = new RequestQueue();
    pthread_mutex_t thread_mutex;
    struct timespec timeout;

    pthread_mutex_init(&thread_mutex, NULL);

    // mutex should be locked
    queue->queueLock(&thread_mutex);

    clock_gettime(CLOCK_REALTIME, &timeout);
    int result = pthread_mutex_timedlock(&thread_mutex, &timeout);

    CPPUNIT_ASSERT(result != 0);

    queueItem* item = new queueItem();
    item->methodId = 1;

    queue->addItem(0, item);

    // mutex should be unlocked
    clock_gettime(CLOCK_REALTIME, &timeout);
    result = pthread_mutex_timedlock(&thread_mutex, &timeout);
    
    CPPUNIT_ASSERT(result == 0);
}
