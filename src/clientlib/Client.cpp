#include "Client.h"

using namespace kumonosu;
using namespace boost;
using namespace apache::thrift;
using namespace apache::thrift::protocol;
using namespace apache::thrift::transport;

Client::Client(int32_t serviceId) :
    _serviceId(serviceId),
    _serverAddress("localhost"),
    _serverPort(9191),
    _socket(new TSocket(_serverAddress.c_str(), _serverPort)),
    _transport(new TFramedTransport(_socket)),
    _protocol(new TBinaryProtocol(_transport)),
    _client(_protocol)
{
    pthread_mutex_init(&_clientMutex, NULL);
}

Client::Client(int32_t serviceId, int32_t serverPort) :
    _serviceId(serviceId),
    _serverAddress("localhost"),
    _serverPort(serverPort),
    _socket(new TSocket(_serverAddress.c_str(), _serverPort)),
    _transport(new TFramedTransport(_socket)),
    _protocol(new TBinaryProtocol(_transport)),
    _client(_protocol)
{
    pthread_mutex_init(&_clientMutex, NULL);
}

Client::Client(int32_t serviceId,
               std::string serverAddress,
               int32_t serverPort) :
    _serviceId(serviceId),
    _serverAddress(serverAddress),
    _serverPort(serverPort),
    _socket(new TSocket(_serverAddress.c_str(), _serverPort)),
    _transport(new TFramedTransport(_socket)),
    _protocol(new TBinaryProtocol(_transport)),
    _client(_protocol)
{
    pthread_mutex_init(&_clientMutex, NULL);
}

Client::~Client()
{
    disconnect();
}

void
Client::connect()
{
    pthread_mutex_lock(&_clientMutex);
    
    if (!_transport->isOpen()) {
        _transport->open();
    }

    pthread_mutex_unlock(&_clientMutex);
}

void
Client::disconnect()
{
    pthread_mutex_lock(&_clientMutex);
    
    if (_transport->isOpen()) {
        _transport->close();
    }

    pthread_mutex_unlock(&_clientMutex);
}

void
Client::setServerAddress(std::string serverAddress)
{
    _serverAddress = serverAddress;

    disconnect();

    pthread_mutex_lock(&_clientMutex);

    _socket = shared_ptr<TTransport>
        (new TSocket(_serverAddress.c_str(), _serverPort));
    _transport = shared_ptr<TTransport>
        (new TFramedTransport(_socket));
    _protocol = shared_ptr<TProtocol>
        (new TBinaryProtocol(_transport));
    _client = *(new LocalRequestManagerClient(_protocol));

    pthread_mutex_unlock(&_clientMutex);
}

void
Client::setServerPort(int32_t serverPort)
{
    _serverPort = serverPort;

    disconnect();

    pthread_mutex_lock(&_clientMutex);

    _socket = shared_ptr<TTransport>
        (new TSocket(_serverAddress.c_str(), _serverPort));
    _transport = shared_ptr<TTransport>
        (new TFramedTransport(_socket));
    _protocol = shared_ptr<TProtocol>
        (new TBinaryProtocol(_transport));
    _client = *(new LocalRequestManagerClient(_protocol));

    pthread_mutex_unlock(&_clientMutex);
}

bool
Client::sendRequest(int32_t serviceId, queueItem item)
{
    bool result = false;
    
    if (!_transport->isOpen()) {
        connect();
    }

    pthread_mutex_lock(&_clientMutex);

    if (_transport->isOpen()) {
        _client.QueueItem(serviceId, item);
        result = true;
    }
    
    pthread_mutex_unlock(&_clientMutex);

    return result;
}

bool
Client::sendLocalRequest(queueItem item)
{
    bool result = false;
    
    if (!_transport->isOpen()) {
        connect();
    }

    pthread_mutex_lock(&_clientMutex);

    if (_transport->isOpen()) {
        _client.QueueInternalItem(item);
        result = true;
    }

    pthread_mutex_unlock(&_clientMutex);

    return result;
}

queueItem
Client::getNextPendingItem()
{
    queueItem result_item;
    
    if (!_transport->isOpen()) {
        connect();
    }
    
    pthread_mutex_lock(&_clientMutex);
    
    _client.GetItem(result_item, _serviceId);

    pthread_mutex_unlock(&_clientMutex);
    
    return result_item;
}

queueItemList
Client::getPendingItems()
{
    queueItemList result_list;

    pthread_mutex_lock(&_clientMutex);

    _client.GetItemList(result_list, _serviceId);

    pthread_mutex_unlock(&_clientMutex);

    return result_list;
}

queueItemList
Client::getPendingItems(int32_t count)
{
    queueItemList result_list;

    pthread_mutex_lock(&_clientMutex);

    _client.GetItemListByCount(result_list, _serviceId, count);

    pthread_mutex_unlock(&_clientMutex);

    return result_list;
}
