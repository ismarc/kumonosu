#include "InternalMessageProcessor.h"
#include "LocalRequestManagerHandler.h"
#include "OutgoingClient.h"
#include "RemoteRequestManagerHandler.h"
#include "RequestQueue.h"

#include <concurrency/ThreadManager.h>
#include <concurrency/PosixThreadFactory.h>
#include <protocol/TBinaryProtocol.h>
#ifdef asdflkjfdsaj
#include <server/TSimpleServer.h>
#endif
#include <server/TNonblockingServer.h>
#include <transport/TServerSocket.h>
#include <transport/TBufferTransports.h>
#include <pthread.h>

using namespace apache::thrift;
using namespace apache::thrift::concurrency;
using namespace apache::thrift::protocol;
using namespace apache::thrift::server;
using namespace apache::thrift::transport;

using boost::shared_ptr;

using namespace kumonosu;

void*
runProcessor(void *arg)
{
    InternalMessageProcessor* processor;
    processor = (InternalMessageProcessor *) arg;
    processor->run();
}

void*
runServer(void *arg)
{
    TNonblockingServer *server;
    server = (TNonblockingServer *) arg;
    server->serve();
}

void*
runClient(void *arg)
{
    OutgoingClient *client;
    client = (OutgoingClient*) arg;
    client->run();
}

int main(int argc, char **argv)
{
    int remotePort = 9090;
    int localPort = 9191;
    int lrmh_thread_id = 0;
    int rrmh_thread_id = 0;
    int imp_thread_id = 0;
    int oc_thread_id = 0;
    pthread_t lrmh_thread;
    pthread_t rrmh_thread;
    pthread_t imp_thread;
    pthread_t oc_thread;

    // Incoming message queue
    RequestQueue* iqueue = new RequestQueue();
    // Outgoing message queue
    RequestQueue* oqueue = new RequestQueue();
    // Internal message queue
    RequestQueue* imqueue = new RequestQueue();

    // Start the remote and local request handlers
    shared_ptr<TProtocolFactory> protocolFactory(new TBinaryProtocolFactory());
    
    shared_ptr<RemoteRequestManagerHandler>
        remoteHandler(new RemoteRequestManagerHandler(iqueue));
    shared_ptr<TProcessor>
        remoteProcessor(new RemoteRequestManagerProcessor(remoteHandler));
    shared_ptr<ThreadManager>
        remoteThreadManager = ThreadManager::newSimpleThreadManager(10);
    shared_ptr<PosixThreadFactory> remoteThreadFactory =
        shared_ptr<PosixThreadFactory>(new PosixThreadFactory());

    remoteThreadManager->threadFactory(remoteThreadFactory);
    remoteThreadManager->start();

    shared_ptr<LocalRequestManagerHandler>
        localHandler(new LocalRequestManagerHandler(iqueue,
                                                    oqueue,
                                                    imqueue));
    shared_ptr<TProcessor>
        localProcessor(new LocalRequestManagerProcessor(localHandler));
    shared_ptr<ThreadManager>
        localThreadManager = ThreadManager::newSimpleThreadManager(10);
    shared_ptr<PosixThreadFactory> localThreadFactory =
        shared_ptr<PosixThreadFactory>(new PosixThreadFactory());

    localThreadManager->threadFactory(localThreadFactory);
    localThreadManager->start();
    
    TNonblockingServer *remoteServer =
        new TNonblockingServer(remoteProcessor,
                               protocolFactory,
                               9090,
                               remoteThreadManager);

    TNonblockingServer *localServer =
        new TNonblockingServer(localProcessor,
                               protocolFactory,
                               9191,
                               localThreadManager);

    // Start the outgoing client
    OutgoingClient* client = new OutgoingClient(oqueue);

    // Start the internal messaging processor
    InternalMessageProcessor* internalProcessor =
        new InternalMessageProcessor(imqueue,
                                     &(*remoteHandler),
                                     &(*localHandler),
                                     client);

    // Launch the threads
    lrmh_thread_id = pthread_create(&lrmh_thread,
                                    NULL,
                                    runServer,
                                    (void*) localServer);
    rrmh_thread_id = pthread_create(&rrmh_thread,
                                    NULL,
                                    runServer,
                                    (void*) remoteServer);
    oc_thread_id = pthread_create(&oc_thread,
                                  NULL,
                                  runClient,
                                  (void*) client);
    imp_thread_id = pthread_create(&imp_thread,
                                   NULL,
                                   runProcessor,
                                   (void*) internalProcessor);

    // Wait for the threads to finish
    pthread_join(lrmh_thread, NULL);
    pthread_join(rrmh_thread, NULL);
    pthread_join(oc_thread, NULL);
    pthread_join(imp_thread, NULL);
    
    return 0;
}
