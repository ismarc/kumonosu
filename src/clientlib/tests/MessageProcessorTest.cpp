#include "MessageProcessorTest.h"
#include "clientlib/MessageProcessor.h"
#include "kumonosu_server_types.h"
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

class ExampleClass {
public:
    ExampleClass() {}
    ~ExampleClass() {}
    void innerCallbackFunction(arguments testArgs) {}
    void innerCallbackFunctionTwo(arguments testArgs) {}
    static void callbackFunction(void *object, arguments argList)
    {
        ExampleClass *myClass = (ExampleClass *)object;
        myClass->innerCallbackFunction(argList);
    }
    static void callbackFunctionTwo(void *object, arguments argList)
    {
        ExampleClass *myClass = (ExampleClass *)object;
        myClass->innerCallbackFunctionTwo(argList);
    }
};

void*
runServer(void* arg)
{
    TSimpleServer *server;
    server = (TSimpleServer *) arg;
    server->serve();
}

void
MessageProcessorTest::constructorTest()
{
    ExampleClass* example = new ExampleClass();
    MessageProcessor* processor = new MessageProcessor((void *)example,
                                                       &ExampleClass::
                                                       callbackFunction);

    CPPUNIT_ASSERT(processor != NULL);
}

void
MessageProcessorTest::setClientTest()
{
    ExampleClass* example = new ExampleClass();
    MessageProcessor* processor = new MessageProcessor((void *)example,
                                                       &ExampleClass::
                                                       callbackFunction);

    Client* client = new Client(1);
    processor->setClient(client);

    CPPUNIT_ASSERT(client != NULL &&
                   processor != NULL);
}

void
MessageProcessorTest::setMethodCallbackTest()
{
    ExampleClass* example = new ExampleClass();
    MessageProcessor* processor = new MessageProcessor((void *)example,
                                                       &ExampleClass::
                                                       callbackFunction);
    processor->setMethodCallback(1,
                                 (void *)example,
                                 &ExampleClass::callbackFunctionTwo);
    CPPUNIT_ASSERT(processor != NULL);
}

void
MessageProcessorTest::removeMethodCallbackTest()
{
    ExampleClass* example = new ExampleClass();
    MessageProcessor* processor = new MessageProcessor((void *)example,
                                                       &ExampleClass::
                                                       callbackFunction);
    processor->setMethodCallback(1,
                                 (void *)example,
                                 &ExampleClass::callbackFunctionTwo);

    processor->removeMethodCallback(1);

    CPPUNIT_ASSERT(processor != NULL);
}

void
MessageProcessorTest::processPendingItemsTest()
{
    ExampleClass* example = new ExampleClass();
    MessageProcessor* processor = new MessageProcessor((void *)example,
                                                       &ExampleClass::
                                                       callbackFunction);
    processor->setMethodCallback(1,
                                 (void *)example,
                                 &ExampleClass::callbackFunctionTwo);
    Client* client = new Client(1);
    processor->setClient(client);

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

    client->connect();

    queueItem item_one;
    queueItem item_two;
    item_one.methodId = 1;
    item_two.methodId = 1;
    
    iqueue->addItem(1, &item_one);
    iqueue->addItem(1, &item_two);
    
    processor->processPendingItems(-1);

    CPPUNIT_ASSERT(client != NULL &&
                   testServer != NULL &&
                   processor != NULL);

    client->disconnect();

    testServer->stop();
    sleep(2);

    delete testServer;
}
