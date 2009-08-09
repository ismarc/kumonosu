#include "RemoteServerTest.h"
#include "RemoteServer.h"
#include "RequestQueue.h"
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
    server = (TSimpleServer *) arg;
    server->serve();
}

void
RemoteServerTest::constructorTest()
{
    // Set up the server so the client has something to talk to
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
    RemoteServer* server = new RemoteServer("localhost", 9090);
    CPPUNIT_ASSERT(server != NULL);
}

void
RemoteServerTest::sendRequestTest()
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
    RemoteServer* server = new RemoteServer("localhost", 9191);
    CPPUNIT_ASSERT(server != NULL);

    int32_t serviceId = 1;
    queueItem item;
    item.methodId = 2;
    CPPUNIT_ASSERT(server->sendRequest(serviceId, item));
}
