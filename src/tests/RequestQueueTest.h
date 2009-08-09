#ifndef kumonosu_RequestQueueTest_h
#define kumonosu_RequestQueueTest_h

#include <cppunit/TestRunner.h>
#include <cppunit/TestResult.h>
#include <cppunit/TestResultCollector.h>
#include <cppunit/extensions/HelperMacros.h>
#include <cppunit/BriefTestProgressListener.h>
#include <cppunit/extensions/TestFactoryRegistry.h>

class RequestQueueTest : public CPPUNIT_NS::TestCase {
    CPPUNIT_TEST_SUITE(RequestQueueTest);
    CPPUNIT_TEST(constructorTest);
    CPPUNIT_TEST(addItemTest);
    CPPUNIT_TEST(getItemTest);
    CPPUNIT_TEST(getItemEmptyTest);
    CPPUNIT_TEST(getItemQueueTest);
    CPPUNIT_TEST(getItemQueueByCountTest);
    CPPUNIT_TEST(getServiceIdsTest);
    CPPUNIT_TEST(queueLockTest);
    CPPUNIT_TEST_SUITE_END();
public:
    void setUp(void) {}
    void tearDown(void) {}
protected:
    void constructorTest();
    void addItemTest();
    void getItemTest();
    void getItemEmptyTest();
    void getItemQueueTest();
    void getItemQueueByCountTest();
    void getServiceIdsTest();
    void queueLockTest();
};

#endif
