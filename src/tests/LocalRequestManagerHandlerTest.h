#ifndef kumonosu_LocalRequestManagerHandlerTest_h
#define kumonosu_LocalRequestManagerHandlerTest_h

#include <cppunit/TestRunner.h>
#include <cppunit/TestResult.h>
#include <cppunit/TestResultCollector.h>
#include <cppunit/extensions/HelperMacros.h>
#include <cppunit/BriefTestProgressListener.h>
#include <cppunit/extensions/TestFactoryRegistry.h>

class LocalRequestManagerHandlerTest : public CPPUNIT_NS::TestCase {
    CPPUNIT_TEST_SUITE(LocalRequestManagerHandlerTest);
    CPPUNIT_TEST(constructorTest);
    CPPUNIT_TEST(setIncomingQueueTest);
    CPPUNIT_TEST(setOutgoingQueueTest);
    CPPUNIT_TEST(setLocalQueueTest);
    CPPUNIT_TEST(queueItemTest);
    CPPUNIT_TEST(getItemTest);
    CPPUNIT_TEST(getItemListTest);
    CPPUNIT_TEST(getItemListByCountTest);
    CPPUNIT_TEST_SUITE_END();
public:
    void setUp(void) {}
    void tearDown(void) {}
protected:
    void constructorTest();
    void setIncomingQueueTest();
    void setOutgoingQueueTest();
    void setLocalQueueTest();
    void queueItemTest();
    void queueItemInternalTest();
    void getItemTest();
    void getItemListTest();
    void getItemListByCountTest();
};

#endif
