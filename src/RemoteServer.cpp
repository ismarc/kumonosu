#include "RemoteServer.h"

using namespace kumonosu;
using namespace boost;
using namespace apache::thrift;
using namespace apache::thrift::protocol;
using namespace apache::thrift::transport;

RemoteServer::RemoteServer(std::string serverAddress, int32_t serverPort) :
    _socket(new TSocket(serverAddress.c_str(), serverPort)),
    _transport(new TFramedTransport(_socket)),
    _protocol(new TBinaryProtocol(_transport)),
    _client(_protocol)
{
    _serverAddress = serverAddress;
    _serverPort = serverPort;

    pthread_mutex_init(&_clientMutex, NULL);
    _transport->open();
}

RemoteServer::~RemoteServer()
{
    pthread_mutex_lock(&_clientMutex);

    if (_transport->isOpen()) {
        _transport->close();
    }

    pthread_mutex_unlock(&_clientMutex);
}

std::string
RemoteServer::getServerAddress()
{
    return _serverAddress;
}

int32_t
RemoteServer::getServerPort()
{
    return _serverPort;
}

bool
RemoteServer::sendRequest(int32_t serviceId, queueItem item)
{
    bool result = false;

    pthread_mutex_lock(&_clientMutex);

    if (_transport->isOpen()) {
        _client.QueueItem(serviceId, item);
        result = true;
    }

    pthread_mutex_unlock(&_clientMutex);

    return result;
}
