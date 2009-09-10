#include "ServiceListArguments.h"

using namespace kumonosu;
using namespace kumonosu::manager;

ServiceListArguments::ServiceListArguments()
{
}

ServiceListArguments::ServiceListArguments(std::vector<int32_t> services) :
    _services(services)
{
}

ServiceListArguments::~ServiceListArguments()
{
}

void
ServiceListArguments::addToArguments(arguments* args)
{
    for (int i = 0; i < _services.size(); i++) {
        i32Arg serviceId;
        serviceId.name = "serviceid";
        serviceId.value = _services[i];
        args->i32Args.push_back(serviceId);
    }
}

void
ServiceListArguments::loadFromArguments(arguments args)
{
    for (int i = 0; i < args.i32Args.size(); i++) {
        if (args.i32Args[i].name == "serviceid") {
            _services.push_back(args.i32Args[i].value);
        }
    }
}
