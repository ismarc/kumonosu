#include "KumonosuManagerTest.h"
#include "manager/KumonosuManager.h"

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

    CPPUNIT_ASSERT(manager != NULL);
}

void
KumonosuManagerTest::runTest()
{
    KumonosuManager* manager = new KumonosuManager();

    pthread_t managerThread;

    pthread_create(&managerThread, NULL, runManager, (void*) manager);

    // Pause to let it actually run some
    sleep(1);

    CPPUNIT_ASSERT(manager != NULL);
    
    // Shut down the manager
    manager->stop();

    CPPUNIT_ASSERT(manager != NULL);
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

    CPPUNIT_ASSERT(manager != NULL);

    // Shut down the manager
    manager->stop();

    CPPUNIT_ASSERT(manager != NULL);

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

    // Set up the invalid method call
    queueItem* item = new queueItem();
    item->methodId = 800;
    iqueue->addItem(0, item);

    // Create the manager
    KumonosuManager* manager = new KumonosuManager();

    // Set the manager to run, invoking the methodNotFound call
    pthread_t managerThread;

    pthread_create(&managerThread, NULL, runManager, (void*) manager);

    // Pause to let it run some
    sleep(4);
    manager->stop();
    CPPUNIT_ASSERT(iqueue->getItemQueue(0).size() == 0);
    testServer->stop();
}
