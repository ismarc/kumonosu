#include "OutgoingClientTest.h"
#include "OutgoingClient.h"

// For the server to connect to
#include "RemoteRequestManagerHandler.h"
#include <protocol/TBinaryProtocol.h>
#include <server/TSimpleServer.h>
#include <transport/TServerSocket.h>
#include <transport/TBufferTransports.h>
#include <pthread.h>

using namespace apache::thrift;
using namespace apache::thrift::protocol;
using namespace apache::thrift::transport;
using namespace apache::thrift::server;
using boost::shared_ptr;

using namespace kumonosu;

void*
runServer(void *arg)
{
    TSimpleServer *server;
    server = (TSimpleServer*) arg;
    server->serve();
}

void*
runClient(void *arg)
{
    OutgoingClient *client;
    client = (OutgoingClient*) arg;
    client->run();
}

void
OutgoingClientTest::constructorTest()
{
    RequestQueue* queue = new RequestQueue;
    OutgoingClient* client = new OutgoingClient(queue);

    CPPUNIT_ASSERT(client != NULL);
}

void
OutgoingClientTest::setOutgoingQueueTest()
{
    RequestQueue* queue = new RequestQueue();
    RequestQueue* new_queue = new RequestQueue();
    OutgoingClient* client = new OutgoingClient(queue);

    client->setOutgoingQueue(new_queue);

    CPPUNIT_ASSERT(client != NULL);
}

void
OutgoingClientTest::addServerTest()
{
    // Set up the listening server
    int port = 9090;
    pthread_t serverThread;
    RequestQueue* queue = new RequestQueue();

    shared_ptr<RemoteRequestManagerHandler> handler(new RemoteRequestManagerHandler(queue));
    shared_ptr<TProcessor> processor(new RemoteRequestManagerProcessor(handler));
    shared_ptr<TServerTransport> transport(new TServerSocket(port));
    shared_ptr<TTransportFactory> transportFactory(new TBufferedTransportFactory());
    shared_ptr<TProtocolFactory> protocolFactory(new TBinaryProtocolFactory());

    TSimpleServer *testServer = new TSimpleServer(processor,
                                              transport,
                                              transportFactory,
                                              protocolFactory);
    pthread_create(&serverThread, NULL, runServer, (void*) testServer);
    sleep(1);

    // Set up the client
    OutgoingClient* client = new OutgoingClient(queue);
    int32_t serverId = 1;
    std::vector<int32_t> serviceIds;
    serviceIds.push_back(2);
    std::string serverAddress = "localhost";
    int32_t serverPort = 9090;

    client->addServer(serverId, serviceIds, serverAddress, serverPort);

    CPPUNIT_ASSERT(client != NULL);

    delete testServer;
}

void
OutgoingClientTest::removeServerTest()
{
    int port = 9191;
    pthread_t serverThread;
    RequestQueue* queue = new RequestQueue();

    shared_ptr<RemoteRequestManagerHandler> handler(new RemoteRequestManagerHandler(queue));
    shared_ptr<TProcessor> processor(new RemoteRequestManagerProcessor(handler));
    shared_ptr<TServerTransport> transport(new TServerSocket(port));
    shared_ptr<TTransportFactory> transportFactory(new TBufferedTransportFactory());
    shared_ptr<TProtocolFactory> protocolFactory(new TBinaryProtocolFactory());

    TSimpleServer *testServer = new TSimpleServer(processor,
                                              transport,
                                              transportFactory,
                                              protocolFactory);
    pthread_create(&serverThread, NULL, runServer, (void*) testServer);
    sleep(1);

    OutgoingClient* client = new OutgoingClient(queue);
    int32_t serverId = 1;
    std::vector<int32_t> serviceIds;
    serviceIds.push_back(2);
    std::string serverAddress = "localhost";
    int32_t serverPort = 9191;

    client->addServer(serverId, serviceIds, serverAddress, serverPort);

    CPPUNIT_ASSERT(client != NULL);

    client->removeServer(serverId);

    CPPUNIT_ASSERT(client != NULL);
    delete testServer;
}

void
OutgoingClientTest::runTest()
{
    RequestQueue* queue = new RequestQueue();
    OutgoingClient* client = new OutgoingClient(queue);

    pthread_t clientThread;

    pthread_create(&clientThread, NULL, runClient, (void*) client);

    sleep(1);
    CPPUNIT_ASSERT(client != NULL);

    // This should return immediately
    client->run();
    client->shutdown();
}

void
OutgoingClientTest::processOutgoingQueueTest()
{
    // Set up the client
    RequestQueue* queue = new RequestQueue();
    OutgoingClient* client = new OutgoingClient(queue);
    pthread_t clientThread;

    pthread_create(&clientThread, NULL, runClient, (void*) client);

    sleep(1);
    CPPUNIT_ASSERT(client != NULL);

    client->run();
        
    // Set up the server
    pthread_t serverThread;
    RequestQueue* iqueue = new RequestQueue();
    int32_t port = 9292;
    shared_ptr<RemoteRequestManagerHandler> handler(new RemoteRequestManagerHandler(iqueue));
    shared_ptr<TProcessor> processor(new RemoteRequestManagerProcessor(handler));
    shared_ptr<TServerTransport> transport(new TServerSocket(port));
    shared_ptr<TTransportFactory> transportFactory(new TBufferedTransportFactory());
    shared_ptr<TProtocolFactory> protocolFactory(new TBinaryProtocolFactory());

    TSimpleServer *testServer = new TSimpleServer(processor,
                                              transport,
                                              transportFactory,
                                              protocolFactory);
    pthread_create(&serverThread, NULL, runServer, (void*) testServer);
    sleep(1);

    // Add the server to the client
    int32_t serverId = 1;
    std::vector<int32_t> serviceIds;
    serviceIds.push_back(2);
    client->addServer(serverId, serviceIds, "localhost", port);

    // Add an item to the client's queue
    queueItem item;
    item.methodId = 1;
    item.serverId = 1;
    queue->addItem(2, &item);

    // Give it time to process
    sleep(1);
    CPPUNIT_ASSERT(queue->getItemQueue(2).size() == 0);

    client->shutdown();
    delete testServer;
}
