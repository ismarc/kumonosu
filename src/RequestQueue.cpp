#include "RequestQueue.h"

using namespace kumonosu;
/** 
 *  Constructor, initializes _dataStoreMutex
 */
RequestQueue::RequestQueue()
{
    // Initialize the mutex
    pthread_mutex_init(&_dataStoreMutex, NULL);
}

/** 
 *  Adds an item to the end of the queue for the specified service id
 */
void
RequestQueue::addItem(int32_t serviceId, queueItem *item)
{
    // Lock the data store
    pthread_mutex_lock(&_dataStoreMutex);

    // If the entry doesn't exist, create it
    if (_requestMap.count(serviceId) == 0) {
        std::queue<queueItem*> newServiceQueue;
        _requestMap[serviceId] = newServiceQueue;
    }

    // Add the item to the queue
    _requestMap[serviceId].push(item);

    // Unlock the data store
    pthread_mutex_unlock(&_dataStoreMutex);

    // Unlock all the mutexes listening for items
    while (_itemAddedMutexList.size() > 0) {
        pthread_mutex_unlock(_itemAddedMutexList.back());
        _itemAddedMutexList.pop_back();
    }
}

/** 
 *  Retrieves the next item in the specified queue
 */
queueItem*
RequestQueue::getItem(int32_t serviceId)
{
    queueItem* result;
    
    // Lock the data store
    pthread_mutex_lock(&_dataStoreMutex);

    // Verify if the queue exists to prevent accidentally creating it
    if (_requestMap.count(serviceId) != 0) {
        result = _requestMap[serviceId].front();
        _requestMap[serviceId].pop();
    }

    // Unlock the data store
    pthread_mutex_unlock(&_dataStoreMutex);
    return result;
}

/** 
 *  Retrieves the entire associated queue
 */
std::queue<queueItem*>
RequestQueue::getItemQueue(int32_t serviceId)
{
    std::queue<queueItem*> result;
    // Lock the data store
    pthread_mutex_lock(&_dataStoreMutex);

    // Verify if the queue exists to prevent accidentally adding it
    if (_requestMap.count(serviceId) != 0) {
        // Assign the queue
        result = _requestMap[serviceId];
        // This is the full queue, so remove from the map
        _requestMap.erase(serviceId);
    }

    // Unlock the data store
    pthread_mutex_unlock(&_dataStoreMutex);
    return result;
}

/** 
 *  Retrieves the next count items in the queue
 */
std::queue<queueItem*>
RequestQueue::getItemQueue(int32_t serviceId, int32_t count)
{
    std::queue<queueItem*> result;
    int current_count = 0;
    
    // Lock the data store
    pthread_mutex_lock(&_dataStoreMutex);

    // Verify if the queue exists to prevent accidentally adding it
    if (_requestMap.count(serviceId) != 0) {
        while (current_count < count &&
               !_requestMap[serviceId].empty()) {
            result.push(_requestMap[serviceId].front());
            _requestMap[serviceId].pop();
            current_count++;
        }

        // Clean up the map if the last item in the queue was removed
        if (_requestMap[serviceId].empty()) {
            _requestMap.erase(serviceId);
        }
    }

    // Unlock the data store
    pthread_mutex_unlock(&_dataStoreMutex);
    return result;
}

/** 
 *  Retrieves the list of service ids that are used in the map
 */
std::vector<int32_t>
RequestQueue::getServiceIds()
{
    std::vector<int32_t> result;

    // Lock the data store
    pthread_mutex_lock(&_dataStoreMutex);

    // Iterate over the map to retrieve each of the keys
    for (std::map<int32_t, std::queue<queueItem*> >::iterator it = _requestMap.begin();
         it != _requestMap.end();
         ++it) {
        result.push_back(it->first);
    }
         
    // Unlock the data store
    pthread_mutex_unlock(&_dataStoreMutex);
    return result;
}

void
RequestQueue::queueLock(pthread_mutex_t* mutex)
{
    pthread_mutex_lock(mutex);
    _itemAddedMutexList.push_back(mutex);
}
