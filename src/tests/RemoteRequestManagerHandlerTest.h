#ifndef kumonosu_RemoteRequestManagerHandlerTest_h
#define kumonosu_RemoteRequestManagerHandlerTest_h

#include <cppunit/TestRunner.h>
#include <cppunit/TestResult.h>
#include <cppunit/TestResultCollector.h>
#include <cppunit/extensions/HelperMacros.h>
#include <cppunit/BriefTestProgressListener.h>
#include <cppunit/extensions/TestFactoryRegistry.h>

class RemoteRequestManagerHandlerTest : public CPPUNIT_NS::TestCase {
    CPPUNIT_TEST_SUITE(RemoteRequestManagerHandlerTest);
    CPPUNIT_TEST(constructorTest);
    CPPUNIT_TEST(setRequestQueueTest);
    CPPUNIT_TEST(queueItemTest);
    CPPUNIT_TEST_SUITE_END();
public:
    void setUp(void) {}
    void tearDown(void) {}
protected:
    void constructorTest();
    void setRequestQueueTest();
    void queueItemTest();
};

#endif
