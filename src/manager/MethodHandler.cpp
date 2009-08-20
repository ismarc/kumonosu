#include "MethodHandler.h"
#include "manager/KumonosuManager.h"

using namespace kumonosu::manager;

void
MethodHandler::methodNotFound(void *object, arguments argList)
{
    KumonosuManager *manager = (KumonosuManager *)object;
    manager->methodNotFound(argList);
}

void
MethodHandler::ping(void *object, arguments argList)
{
    KumonosuManager *manager = (KumonosuManager *)object;
    manager->ping(argList);
}

void
MethodHandler::pong(void *object, arguments argList)
{
    KumonosuManager *manager = (KumonosuManager *)object;
    manager->pong(argList);
}

void
MethodHandler::getServerList(void *object, arguments argList)
{
    KumonosuManager *manager = (KumonosuManager *)object;
    manager->getServerList(argList);
}

void
MethodHandler::getServerListResponse(void *object, arguments argList)
{
    KumonosuManager *manager = (KumonosuManager *)object;
    manager->getServerListResponse(argList);
}

void
MethodHandler::getServiceList(void *object, arguments argList)
{
    KumonosuManager *manager = (KumonosuManager *)object;
    manager->getServiceList(argList);
}

void
MethodHandler::getServiceListResponse(void *object, arguments argList)
{
    KumonosuManager *manager = (KumonosuManager *)object;
    manager->getServiceListResponse(argList);
}
