#include "CallbackTest.h"
#include "clientlib/Callback.h"
#include "kumonosu_server_types.h"

using namespace kumonosu;

class ExampleClass {
public:
public:
    ExampleClass() {}
    ~ExampleClass() {}
    void innerCallbackFunction(arguments testArgs) {}
    static void callbackFunction(void *object, arguments argList)
    {
        ExampleClass *myClass = (ExampleClass *)object;
        myClass->innerCallbackFunction(argList);
    }
};

void
CallbackTest::constructorTest()
{
    ExampleClass* example = new ExampleClass();
    Callback callback((void *)example, &ExampleClass::callbackFunction);

    CPPUNIT_ASSERT(example != NULL);
}

void
CallbackTest::executeTest()
{
    ExampleClass* example = new ExampleClass();
    Callback callback((void *)example, &ExampleClass::callbackFunction);

    arguments args;
    callback.execute(args);

    CPPUNIT_ASSERT(example != NULL);
}
