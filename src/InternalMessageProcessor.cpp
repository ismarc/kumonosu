#include "InternalMessageProcessor.h"

using namespace kumonosu;

InternalMessageProcessor::InternalMessageProcessor(RequestQueue* internalQueue,
                                                   RemoteRequestManagerHandler* rHandler,
                                                   LocalRequestManagerHandler* lHandler,
                                                   OutgoingClient* client) :
    _internalQueue(internalQueue),
    _remoteHandler(rHandler),
    _localHandler(lHandler),
    _client(client),
    _shutdown(false)
{
    pthread_mutex_init(&_runMutex, NULL);
    pthread_mutex_init(&_queuedItemMutex, NULL);
}

void
InternalMessageProcessor::setInternalQueue(RequestQueue* internalQueue)
{
    _internalQueue = internalQueue;
}

void
InternalMessageProcessor::setRemoteHandler(RemoteRequestManagerHandler* handler)
{
    _remoteHandler = handler;
}

void
InternalMessageProcessor::setLocalHandler(LocalRequestManagerHandler* handler)
{
    _localHandler = handler;
}

void
InternalMessageProcessor::setOutgoingClient(OutgoingClient* client)
{
    _client = client;
}

void
InternalMessageProcessor::run()
{
    int runfailed = -1;
    struct timespec check_timeout;
    clock_gettime(CLOCK_REALTIME, &check_timeout);

    runfailed = pthread_mutex_timedlock(&_runMutex, &check_timeout);

    if (runfailed) {
        return;
    }
    
    // Kinda hacky, is this a good way?
    // queueLock locks the lock.  RequestQueue unlocks the lock when
    // an item is added to the queue, allowing us to block until items
    // are ready to be processed.
    _internalQueue->queueLock(&_queuedItemMutex);
    while(!_shutdown) {
        struct timespec timeout;
        int result = -1;
        
        clock_gettime(CLOCK_REALTIME, &timeout);
        timeout.tv_sec += 10; // Wait 10 seconds for timeout
        
        result = pthread_mutex_timedlock(&_queuedItemMutex, &timeout);

        // timedlock returns 0 on success, other on error/timeout
        if (!result) {
            // Do the processing of the queue item here
            processReadyQueue();

            pthread_mutex_unlock(&_queuedItemMutex);
            _internalQueue->queueLock(&_queuedItemMutex);
        }
    }

    pthread_mutex_unlock(&_runMutex);
}

void
InternalMessageProcessor::shutdown()
{
    _shutdown = true;
}

void
InternalMessageProcessor::processReadyQueue()
{
    std::queue<queueItem*> itemQueue;
    // All internal items are service id 0
    itemQueue = _internalQueue->getItemQueue(0);

    while (!itemQueue.empty()) {
        processQueueItem(itemQueue.front());
        itemQueue.pop();
    }
}

void
InternalMessageProcessor::processQueueItem(queueItem* item)
{
    int methodId = item->methodId;
    int serverId = item->serverId;
    arguments argList = item->argList;

    // Only know how to handle method id 1 (shutdown) now
    if (methodId == 1) {
        // shutdown the processor
        _shutdown = true;
    }
}
    
