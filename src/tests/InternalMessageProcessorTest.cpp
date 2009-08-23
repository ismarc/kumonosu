#include "InternalMessageProcessorTest.h"
#include "InternalMessageProcessor.h"
#include "RequestQueue.h"

using namespace kumonosu;

void
InternalMessageProcessorTest::constructorTest()
{
    RequestQueue* queue = new RequestQueue();
    InternalMessageProcessor* processor = new InternalMessageProcessor(queue,
                                                                       NULL,
                                                                       NULL,
                                                                       NULL);
    CPPUNIT_ASSERT(processor != NULL);
}

void
InternalMessageProcessorTest::setInternalQueueTest()
{
    RequestQueue* queue = new RequestQueue();
    RequestQueue* new_queue = new RequestQueue();
    InternalMessageProcessor* processor = new InternalMessageProcessor(queue,
                                                                       NULL,
                                                                       NULL,
                                                                       NULL);
    processor->setInternalQueue(new_queue);
    CPPUNIT_ASSERT(processor != NULL);
}

void
InternalMessageProcessorTest::runTest()
{
    RequestQueue* queue = new RequestQueue();
    InternalMessageProcessor* processor = new InternalMessageProcessor(queue,
                                                                       NULL,
                                                                       NULL,
                                                                       NULL);
    pthread_t processorThread;
    
    pthread_create(&processorThread, NULL, runProcessor, (void*) processor);

    // Wait a bit for the run to get processed
    sleep(1);
    CPPUNIT_ASSERT(processor != NULL);

    // This run should return immediately
    processor->run();
    
    processor->shutdown();
}

void
InternalMessageProcessorTest::processItemTest()
{
    RequestQueue* queue = new RequestQueue();
    InternalMessageProcessor* processor = new InternalMessageProcessor(queue,
                                                                       NULL,
                                                                       NULL,
                                                                       NULL);
    pthread_t processorThread;

    pthread_create(&processorThread, NULL, runProcessor, (void*) processor);

    // Wait a bit for the run to get processed
    sleep(1);
    CPPUNIT_ASSERT(processor != NULL);

    // Add an item to the queue for the processor to grab
    queueItem *item = new queueItem();
    item->methodId = 1;
    
    queue->addItem(0, item);

    // Let it get processed
    sleep(1);
    
    // Verify the item is no longer in the queue
    CPPUNIT_ASSERT(queue->getItemQueue(0).size() == 0);

    // The item should have caused shutdown, so we shouldn't be
    // blocking here
}

void
InternalMessageProcessorTest::getServerListTest()
{
    RequestQueue* queue = new RequestQueue();
    InternalMessageProcessor* processor = new InternalMessageProcessor(queue,
                                                                       NULL,
                                                                       NULL,
                                                                       NULL);
    OutgoingClient* client = new OutgoingClient(queue);
    processor->getServerList(1);
    CPPUNIT_ASSERT(queue->getItemQueue(1).size() != 0);
}

void*
runProcessor(void *arg)
{
    InternalMessageProcessor* processor;
    processor = (InternalMessageProcessor *) arg;
    processor->run();
}
