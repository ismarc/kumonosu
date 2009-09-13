#include "KumonosuManagerTest.h"
#include "manager/KumonosuManager.h"
#include "manager/ManagerMethodMap.h"
#include "manager/ping_arguments.h"

#include "RequestQueue.h"
#include "LocalRequestManagerHandler.h"

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
using namespace kumonosu::manager;

void*
runManager(void* arg)
{
    KumonosuManager* manager;
    manager = (KumonosuManager *) arg;
    manager->run();
}

void*
runServer(void* arg)
{
    TSimpleServer* server;
    server = (TSimpleServer *) arg;
    server->serve();
}

void
KumonosuManagerTest::constructorTest()
{
    KumonosuManager* manager = new KumonosuManager();

    CPPUNIT_ASSERT_MESSAGE("manager is NULL", manager != NULL);
}

void
KumonosuManagerTest::runTest()
{
    KumonosuManager* manager = new KumonosuManager();

    pthread_t managerThread;

    pthread_create(&managerThread, NULL, runManager, (void*) manager);

    // Pause to let it actually run some
    sleep(1);

    CPPUNIT_ASSERT_MESSAGE("manager is NULL", manager != NULL);
    
    // Shut down the manager
    manager->stop();

    CPPUNIT_ASSERT_MESSAGE("manager is NULL after stop()",manager != NULL);
}

void
KumonosuManagerTest::runWithClientTest()
{
    // Set up the server
    pthread_t serverThread;
    RequestQueue* iqueue = new RequestQueue();
    RequestQueue* oqueue = new RequestQueue();
    RequestQueue* imqueue = new RequestQueue();

    shared_ptr<LocalRequestManagerHandler> handler
        (new LocalRequestManagerHandler(iqueue, oqueue, imqueue));
    shared_ptr<TProcessor> serverProcessor
        (new LocalRequestManagerProcessor(handler));
    shared_ptr<TServerTransport> transport(new TServerSocket(9191));
    shared_ptr<TTransportFactory> transportFactory
        (new TBufferedTransportFactory());
    shared_ptr<TProtocolFactory> protocolFactory(new TBinaryProtocolFactory());

    TSimpleServer *testServer = new TSimpleServer(serverProcessor,
                                                  transport,
                                                  transportFactory,
                                                  protocolFactory);

    pthread_create(&serverThread, NULL, runServer, (void*) testServer);
    sleep(2);

    // Set up the manager
    KumonosuManager* manager = new KumonosuManager();
    pthread_t managerThread;

    pthread_create(&managerThread, NULL, runManager, (void*) manager);

    // Pause to let it actually run some
    sleep(1);

    CPPUNIT_ASSERT_MESSAGE("manager is NULL", manager != NULL);

    // Shut down the manager
    manager->stop();

    CPPUNIT_ASSERT_MESSAGE("manager is NULL after stop()",manager != NULL);

    // Shut down the server
    testServer->stop();
}

void
KumonosuManagerTest::methodNotFoundTest()
{
    // Set up the server
    pthread_t serverThread;
    RequestQueue* iqueue = new RequestQueue();
    RequestQueue* oqueue = new RequestQueue();
    RequestQueue* imqueue = new RequestQueue();

    shared_ptr<LocalRequestManagerHandler> handler
        (new LocalRequestManagerHandler(iqueue, oqueue, imqueue));
    shared_ptr<TProcessor> serverProcessor
        (new LocalRequestManagerProcessor(handler));
    shared_ptr<TServerTransport> transport(new TServerSocket(9292));
    shared_ptr<TTransportFactory> transportFactory
        (new TBufferedTransportFactory());
    shared_ptr<TProtocolFactory> protocolFactory(new TBinaryProtocolFactory());

    TSimpleServer *testServer = new TSimpleServer(serverProcessor,
                                                  transport,
                                                  transportFactory,
                                                  protocolFactory);

    pthread_create(&serverThread, NULL, runServer, (void*) testServer);
    sleep(2);

    // Set up the invalid method call
    queueItem* item = new queueItem();
    item->methodId = 800;
    iqueue->addItem(0, item);

    // Create the manager
    KumonosuManager* manager = new KumonosuManager("localhost", 9292);

    // Set the manager to run, invoking the methodNotFound call
    pthread_t managerThread;

    pthread_create(&managerThread, NULL, runManager, (void*) manager);

    // Pause to let it run some
    sleep(4);
    manager->stop();
    CPPUNIT_ASSERT_MESSAGE("item queue size is not 0",
                           iqueue->getItemQueue(0).size() == 0);

    testServer->stop();
}

void
KumonosuManagerTest::pingTest()
{
    pthread_t serverThread;
    RequestQueue* iqueue = new RequestQueue();
    RequestQueue* oqueue = new RequestQueue();
    RequestQueue* imqueue = new RequestQueue();

    shared_ptr<LocalRequestManagerHandler> handler
        (new LocalRequestManagerHandler(iqueue, oqueue, imqueue));
    shared_ptr<TProcessor> serverProcessor
        (new LocalRequestManagerProcessor(handler));
    shared_ptr<TServerTransport> transport(new TServerSocket(9393));
    shared_ptr<TTransportFactory> transportFactory
        (new TBufferedTransportFactory());
    shared_ptr<TProtocolFactory> protocolFactory(new TBinaryProtocolFactory());

    TSimpleServer *testServer = new TSimpleServer(serverProcessor,
                                                  transport,
                                                  transportFactory,
                                                  protocolFactory);

    pthread_create(&serverThread, NULL, runServer, (void*) testServer);
    sleep(2);

    queueItem* item = new queueItem();
    item->methodId = ManagerMethodMap::Ping;

    ping_arguments pingItem("a.badhostname.com", 8989, 24, 0, 1);
    item->argList = (arguments) pingItem;

    iqueue->addItem(0, item);

    KumonosuManager* manager = new KumonosuManager("localhost", 9393);

    // Add the server that would correspond with the Ping response
    // above
    Server newServer;
    newServer.setServerAddress("a.badhostname.com");
    newServer.setServerPort(8989);
    newServer.setServerId(24);

    manager->addServer(newServer);

    pthread_t managerThread;

    pthread_create(&managerThread, NULL, runManager, (void*) manager);

    sleep(4);
    manager->stop();
    testServer->stop();
    CPPUNIT_ASSERT_MESSAGE("Incoming queue is not 0",
                           iqueue->getItemQueue(0).size() == 0);

    CPPUNIT_ASSERT_MESSAGE("Outgoing queue is not 1",
                           oqueue->getItemQueue(0).size() != 0);
}

void
KumonosuManagerTest::pongTest()
{
    pthread_t serverThread;
    RequestQueue* iqueue = new RequestQueue();
    RequestQueue* oqueue = new RequestQueue();
    RequestQueue* imqueue = new RequestQueue();

    shared_ptr<LocalRequestManagerHandler> handler
        (new LocalRequestManagerHandler(iqueue, oqueue, imqueue));
    shared_ptr<TProcessor> serverProcessor
        (new LocalRequestManagerProcessor(handler));
    shared_ptr<TServerTransport> transport(new TServerSocket(9494));
    shared_ptr<TTransportFactory> transportFactory
        (new TBufferedTransportFactory());
    shared_ptr<TProtocolFactory> protocolFactory(new TBinaryProtocolFactory());

    TSimpleServer *testServer = new TSimpleServer(serverProcessor,
                                                  transport,
                                                  transportFactory,
                                                  protocolFactory);

    pthread_create(&serverThread, NULL, runServer, (void*) testServer);
    sleep(2);

    queueItem* item = new queueItem();
    item->methodId = ManagerMethodMap::Pong;
    iqueue->addItem(0, item);

    KumonosuManager* manager = new KumonosuManager("localhost", 9494);

    pthread_t managerThread;

    pthread_create(&managerThread, NULL, runManager, (void*) manager);

    sleep(4);
    manager->stop();
    CPPUNIT_ASSERT_MESSAGE("Incoming queue is not 0",
                           iqueue->getItemQueue(0).size() == 0);

    testServer->stop();
}

void
KumonosuManagerTest::getServerListTest()
{
    pthread_t serverThread;
    RequestQueue* iqueue = new RequestQueue();
    RequestQueue* oqueue = new RequestQueue();
    RequestQueue* imqueue = new RequestQueue();

    shared_ptr<LocalRequestManagerHandler> handler
        (new LocalRequestManagerHandler(iqueue, oqueue, imqueue));
    shared_ptr<TProcessor> serverProcessor
        (new LocalRequestManagerProcessor(handler));
    shared_ptr<TServerTransport> transport(new TServerSocket(9595));
    shared_ptr<TTransportFactory> transportFactory
        (new TBufferedTransportFactory());
    shared_ptr<TProtocolFactory> protocolFactory(new TBinaryProtocolFactory());

    TSimpleServer *testServer = new TSimpleServer(serverProcessor,
                                                  transport,
                                                  transportFactory,
                                                  protocolFactory);

    pthread_create(&serverThread, NULL, runServer, (void*) testServer);
    sleep(2);

    queueItem* item = new queueItem();
    item->methodId = ManagerMethodMap::IMGetServerList;
    i32Arg serverId;
    serverId.name = "serverid";
    serverId.value = 34;
    item->argList.i32Args.push_back(serverId);
    i32Arg serviceId;
    serviceId.name = "serviceid";
    serviceId.value = 0;
    item->argList.i32Args.push_back(serviceId);
    iqueue->addItem(0, item);

    KumonosuManager* manager = new KumonosuManager("localhost", 9595);

    pthread_t managerThread;

    pthread_create(&managerThread, NULL, runManager, (void*) manager);

    sleep(4);
    manager->stop();
    // getServerList should generate an outgoing message
    CPPUNIT_ASSERT_MESSAGE("Incoming queue is not 0",
                           iqueue->getItemQueue(0).size() == 0);

    CPPUNIT_ASSERT_MESSAGE("Outgoing queue is not 1",
                           oqueue->getItemQueue(0).size() == 1);

    testServer->stop();
}

void
KumonosuManagerTest::getServerListResponseTest()
{
    pthread_t serverThread;
    RequestQueue* iqueue = new RequestQueue();
    RequestQueue* oqueue = new RequestQueue();
    RequestQueue* imqueue = new RequestQueue();

    shared_ptr<LocalRequestManagerHandler> handler
        (new LocalRequestManagerHandler(iqueue, oqueue, imqueue));
    shared_ptr<TProcessor> serverProcessor
        (new LocalRequestManagerProcessor(handler));
    shared_ptr<TServerTransport> transport(new TServerSocket(9696));
    shared_ptr<TTransportFactory> transportFactory
        (new TBufferedTransportFactory());
    shared_ptr<TProtocolFactory> protocolFactory(new TBinaryProtocolFactory());

    TSimpleServer *testServer = new TSimpleServer(serverProcessor,
                                                  transport,
                                                  transportFactory,
                                                  protocolFactory);

    pthread_create(&serverThread, NULL, runServer, (void*) testServer);
    sleep(2);

    queueItem* item = new queueItem();
    item->methodId = ManagerMethodMap::IMGetServerResponse;
    iqueue->addItem(0, item);

    KumonosuManager* manager = new KumonosuManager("localhost", 9696);

    pthread_t managerThread;

    pthread_create(&managerThread, NULL, runManager, (void*) manager);

    sleep(4);
    manager->stop();
    CPPUNIT_ASSERT_MESSAGE("Incoming queue is not 0",
                           iqueue->getItemQueue(0).size() == 0);

    testServer->stop();
}

void
KumonosuManagerTest::getServiceListTest()
{
    pthread_t serverThread;
    RequestQueue* iqueue = new RequestQueue();
    RequestQueue* oqueue = new RequestQueue();
    RequestQueue* imqueue = new RequestQueue();

    shared_ptr<LocalRequestManagerHandler> handler
        (new LocalRequestManagerHandler(iqueue, oqueue, imqueue));
    shared_ptr<TProcessor> serverProcessor
        (new LocalRequestManagerProcessor(handler));
    shared_ptr<TServerTransport> transport(new TServerSocket(9797));
    shared_ptr<TTransportFactory> transportFactory
        (new TBufferedTransportFactory());
    shared_ptr<TProtocolFactory> protocolFactory(new TBinaryProtocolFactory());

    TSimpleServer *testServer = new TSimpleServer(serverProcessor,
                                                  transport,
                                                  transportFactory,
                                                  protocolFactory);

    pthread_create(&serverThread, NULL, runServer, (void*) testServer);
    sleep(2);

    queueItem* item = new queueItem();
    item->methodId = ManagerMethodMap::GetServiceList;
    i32Arg serverId;
    serverId.name = "serverid";
    serverId.value = 34;
    item->argList.i32Args.push_back(serverId);
    i32Arg serviceId;
    serviceId.name = "serviceid";
    serviceId.value = 0;
    item->argList.i32Args.push_back(serviceId);

    iqueue->addItem(0, item);

    KumonosuManager* manager = new KumonosuManager("localhost", 9797);

    pthread_t managerThread;

    pthread_create(&managerThread, NULL, runManager, (void*) manager);

    sleep(4);
    manager->stop();
    // getServerList should generate an outgoing message
    CPPUNIT_ASSERT_MESSAGE("Incoming queue is not 0",
                           iqueue->getItemQueue(0).size() == 0);

    CPPUNIT_ASSERT_MESSAGE("Outgoing queue is not 1",
                           oqueue->getItemQueue(0).size() == 1);

    testServer->stop();
}

void
KumonosuManagerTest::getServiceListResponseTest()
{
    pthread_t serverThread;
    RequestQueue* iqueue = new RequestQueue();
    RequestQueue* oqueue = new RequestQueue();
    RequestQueue* imqueue = new RequestQueue();

    shared_ptr<LocalRequestManagerHandler> handler
        (new LocalRequestManagerHandler(iqueue, oqueue, imqueue));
    shared_ptr<TProcessor> serverProcessor
        (new LocalRequestManagerProcessor(handler));
    shared_ptr<TServerTransport> transport(new TServerSocket(9898));
    shared_ptr<TTransportFactory> transportFactory
        (new TBufferedTransportFactory());
    shared_ptr<TProtocolFactory> protocolFactory(new TBinaryProtocolFactory());

    TSimpleServer *testServer = new TSimpleServer(serverProcessor,
                                                  transport,
                                                  transportFactory,
                                                  protocolFactory);

    pthread_create(&serverThread, NULL, runServer, (void*) testServer);
    sleep(2);

    queueItem* item = new queueItem();
    item->methodId = ManagerMethodMap::GetServiceListResponse;
    iqueue->addItem(0, item);

    KumonosuManager* manager = new KumonosuManager("localhost", 9898);

    pthread_t managerThread;

    pthread_create(&managerThread, NULL, runManager, (void*) manager);

    sleep(4);
    manager->stop();
    CPPUNIT_ASSERT_MESSAGE("Incoming queue is not 0",
                           iqueue->getItemQueue(0).size() == 0);

    testServer->stop();
}
