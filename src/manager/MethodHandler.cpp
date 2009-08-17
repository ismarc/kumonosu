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
MethodHandler::getServerListResponse(void *object, arguments argList)
{
    KumonosuManager *manager = (KumonosuManager *)object;
    manager->getServerListResponse(argList);
}
