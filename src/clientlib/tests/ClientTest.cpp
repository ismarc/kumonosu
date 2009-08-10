#include "ClientTest.h"
#include "clientlib/Client.h"
#include "LocalRequestManagerHandler.h"
#include "RequestQueue.h"

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
runServer(void* arg)
{
    TSimpleServer *server;
    server = (TSimpleServer *) arg;
    server->serve();
}

void
ClientTest::constructorTest()
{
    Client* client = new Client(1);
    Client* client_two = new Client(1, 9595);
    Client* client_three = new Client(1, "localhost", 9696);

    CPPUNIT_ASSERT(client != NULL);
    CPPUNIT_ASSERT(client_two != NULL);
    CPPUNIT_ASSERT(client_three != NULL);
}

void
ClientTest::setServerAddressTest()
{
    Client* client = new Client(1, 9494);

    client->setServerAddress("127.0.0.1");
    CPPUNIT_ASSERT(client != NULL);

    pthread_t serverThread;
    RequestQueue* iqueue = new RequestQueue();
    RequestQueue* oqueue = new RequestQueue();
    RequestQueue* imqueue = new RequestQueue();
    
    shared_ptr<LocalRequestManagerHandler> handler
        (new LocalRequestManagerHandler(iqueue, oqueue, imqueue));
    shared_ptr<TProcessor> processor(new LocalRequestManagerProcessor(handler));
    shared_ptr<TServerTransport> transport(new TServerSocket(9494));
    shared_ptr<TTransportFactory> transportFactory
        (new TBufferedTransportFactory());
    shared_ptr<TProtocolFactory> protocolFactory(new TBinaryProtocolFactory());

    TSimpleServer *testServer = new TSimpleServer(processor,
                                                  transport,
                                                  transportFactory,
                                                  protocolFactory);

    pthread_create(&serverThread, NULL, runServer, (void*) testServer);
    sleep(2);

    client->connect();
    client->setServerAddress("localhost");

    CPPUNIT_ASSERT(client != NULL);
    client->disconnect();

    testServer->stop();
    sleep(1);

    delete testServer;
}

void
ClientTest::setServerPortTest()
{
    Client* client = new Client(1);

    client->setServerPort(9393);
    CPPUNIT_ASSERT(client != NULL);

    // Set up a server for use
    pthread_t serverThread;
    RequestQueue* iqueue = new RequestQueue();
    RequestQueue* oqueue = new RequestQueue();
    RequestQueue* imqueue = new RequestQueue();
    
    shared_ptr<LocalRequestManagerHandler> handler
        (new LocalRequestManagerHandler(iqueue, oqueue, imqueue));
    shared_ptr<TProcessor> processor(new LocalRequestManagerProcessor(handler));
    shared_ptr<TServerTransport> transport(new TServerSocket(9393));
    shared_ptr<TTransportFactory> transportFactory
        (new TBufferedTransportFactory());
    shared_ptr<TProtocolFactory> protocolFactory(new TBinaryProtocolFactory());

    TSimpleServer *testServer = new TSimpleServer(processor,
                                                  transport,
                                                  transportFactory,
                                                  protocolFactory);

    pthread_create(&serverThread, NULL, runServer, (void*) testServer);
    sleep(2);

    client->connect();
    client->setServerPort(9393);

    CPPUNIT_ASSERT(client != NULL);
    client->disconnect();

    testServer->stop();
    sleep(1);

    delete testServer;
}

void
ClientTest::connectTest()
{
    Client* client = new Client(1, "localhost", 9292);

    // Set up the server
    pthread_t serverThread;
    RequestQueue* iqueue = new RequestQueue();
    RequestQueue* oqueue = new RequestQueue();
    RequestQueue* imqueue = new RequestQueue();
    
    shared_ptr<LocalRequestManagerHandler> handler
        (new LocalRequestManagerHandler(iqueue, oqueue, imqueue));
    shared_ptr<TProcessor> processor(new LocalRequestManagerProcessor(handler));
    shared_ptr<TServerTransport> transport(new TServerSocket(9292));
    shared_ptr<TTransportFactory> transportFactory
        (new TBufferedTransportFactory());
    shared_ptr<TProtocolFactory> protocolFactory(new TBinaryProtocolFactory());

    TSimpleServer *testServer = new TSimpleServer(processor,
                                                  transport,
                                                  transportFactory,
                                                  protocolFactory);

    pthread_create(&serverThread, NULL, runServer, (void*) testServer);
    sleep(2);

    client->connect();
    CPPUNIT_ASSERT(client != NULL);
    client->disconnect();
    CPPUNIT_ASSERT(client != NULL);

    testServer->stop();
    sleep(1);

    delete testServer;
}

void
ClientTest::sendRequestTest()
{
    Client* client = new Client(1, "localhost", 9696);

    pthread_t serverThread;
    RequestQueue* iqueue = new RequestQueue();
    RequestQueue* oqueue = new RequestQueue();
    RequestQueue* imqueue = new RequestQueue();

    shared_ptr<LocalRequestManagerHandler> handler
        (new LocalRequestManagerHandler(iqueue, oqueue, imqueue));
    shared_ptr<TProcessor> processor(new LocalRequestManagerProcessor(handler));
    shared_ptr<TServerTransport> transport(new TServerSocket(9696));
    shared_ptr<TTransportFactory> transportFactory
        (new TBufferedTransportFactory());
    shared_ptr<TProtocolFactory> protocolFactory(new TBinaryProtocolFactory());

    TSimpleServer *testServer = new TSimpleServer(processor,
                                                  transport,
                                                  transportFactory,
                                                  protocolFactory);

    pthread_create(&serverThread, NULL, runServer, (void*) testServer);
    sleep(2);

    client->connect();

    queueItem item;
    item.methodId = 1;

    CPPUNIT_ASSERT(client->sendRequest(1, item));

    client->disconnect();

    testServer->stop();
    sleep(1);

    delete testServer;
}

void
ClientTest::sendLocalRequestTest()
{
    Client* client = new Client(1, "localhost", 9797);

    pthread_t serverThread;
    RequestQueue* iqueue = new RequestQueue();
    RequestQueue* oqueue = new RequestQueue();
    RequestQueue* imqueue = new RequestQueue();

    shared_ptr<LocalRequestManagerHandler> handler
        (new LocalRequestManagerHandler(iqueue, oqueue, imqueue));
    shared_ptr<TProcessor> processor(new LocalRequestManagerProcessor(handler));
    shared_ptr<TServerTransport> transport(new TServerSocket(9797));
    shared_ptr<TTransportFactory> transportFactory
        (new TBufferedTransportFactory());
    shared_ptr<TProtocolFactory> protocolFactory(new TBinaryProtocolFactory());

    TSimpleServer *testServer = new TSimpleServer(processor,
                                                  transport,
                                                  transportFactory,
                                                  protocolFactory);

    pthread_create(&serverThread, NULL, runServer, (void*) testServer);
    sleep(2);

    client->connect();

    queueItem item;
    item.methodId = 1;

    CPPUNIT_ASSERT(client->sendLocalRequest(item));

    client->disconnect();

    testServer->stop();
    sleep(1);

    delete testServer;
}

void
ClientTest::getNextPendingItemTest()
{
    Client* client = new Client(1, "localhost", 9898);

    pthread_t serverThread;
    RequestQueue* iqueue = new RequestQueue();
    RequestQueue* oqueue = new RequestQueue();
    RequestQueue* imqueue = new RequestQueue();

    shared_ptr<LocalRequestManagerHandler> handler
        (new LocalRequestManagerHandler(iqueue, oqueue, imqueue));
    shared_ptr<TProcessor> processor(new LocalRequestManagerProcessor(handler));
    shared_ptr<TServerTransport> transport(new TServerSocket(9898));
    shared_ptr<TTransportFactory> transportFactory
        (new TBufferedTransportFactory());
    shared_ptr<TProtocolFactory> protocolFactory(new TBinaryProtocolFactory());

    TSimpleServer *testServer = new TSimpleServer(processor,
                                                  transport,
                                                  transportFactory,
                                                  protocolFactory);

    pthread_create(&serverThread, NULL, runServer, (void*) testServer);
    sleep(2);

    client->connect();

    queueItem item;
    queueItem new_item;
    item.methodId = 1;

    iqueue->addItem(1, &item);

    new_item = client->getNextPendingItem();

    CPPUNIT_ASSERT(new_item.methodId == 1);

    client->disconnect();

    testServer->stop();
    sleep(1);

    delete testServer;
}

void
ClientTest::getPendingItemsTest()
{
    Client* client = new Client(1, "localhost", 9999);

    pthread_t serverThread;
    RequestQueue* iqueue = new RequestQueue();
    RequestQueue* oqueue = new RequestQueue();
    RequestQueue* imqueue = new RequestQueue();

    shared_ptr<LocalRequestManagerHandler> handler
        (new LocalRequestManagerHandler(iqueue, oqueue, imqueue));
    shared_ptr<TProcessor> processor(new LocalRequestManagerProcessor(handler));
    shared_ptr<TServerTransport> transport(new TServerSocket(9999));
    shared_ptr<TTransportFactory> transportFactory
        (new TBufferedTransportFactory());
    shared_ptr<TProtocolFactory> protocolFactory(new TBinaryProtocolFactory());

    CPPUNIT_ASSERT(transport.get() != NULL);
    TSimpleServer *testServer = new TSimpleServer(processor,
                                                  transport,
                                                  transportFactory,
                                                  protocolFactory);

    pthread_create(&serverThread, NULL, runServer, (void*) testServer);
    sleep(2);

    client->connect();

    queueItem item_one;
    queueItem item_two;
    item_one.methodId = 1;
    item_two.methodId = 1;

    iqueue->addItem(1, &item_one);
    iqueue->addItem(1, &item_two);

    queueItemList items = client->getPendingItems();

    CPPUNIT_ASSERT(items.items.size() == 2);

    client->disconnect();

    testServer->stop();
    sleep(2);

    delete testServer;
}

void
ClientTest::getPendingItemsCountTest()
{
    Client* client = new Client(1, "localhost", 9192);

    pthread_t serverThread;
    RequestQueue* iqueue = new RequestQueue();
    RequestQueue* oqueue = new RequestQueue();
    RequestQueue* imqueue = new RequestQueue();

    shared_ptr<LocalRequestManagerHandler> handler
        (new LocalRequestManagerHandler(iqueue, oqueue, imqueue));
    shared_ptr<TProcessor> processor(new LocalRequestManagerProcessor(handler));
    shared_ptr<TServerTransport> transport(new TServerSocket(9192));
    shared_ptr<TTransportFactory> transportFactory
        (new TBufferedTransportFactory());
    shared_ptr<TProtocolFactory> protocolFactory(new TBinaryProtocolFactory());

    TSimpleServer *testServer = new TSimpleServer(processor,
                                                  transport,
                                                  transportFactory,
                                                  protocolFactory);

    pthread_create(&serverThread, NULL, runServer, (void*) testServer);
    sleep(2);

    client->connect();

    queueItem item_one;
    queueItem item_two;

    item_one.methodId = 1;
    item_two.methodId = 1;

    iqueue->addItem(1, &item_one);
    iqueue->addItem(1, &item_two);

    queueItemList items = client->getPendingItems(1);

    CPPUNIT_ASSERT(items.items.size() == 1);

    client->disconnect();

    testServer->stop();
    sleep(2);

    delete testServer;
}
