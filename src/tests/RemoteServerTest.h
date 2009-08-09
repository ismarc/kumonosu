#ifndef kumonosu_RemoteServerTest_h
#define kumonosu_RemoteServerTest_h

#include <cppunit/TestRunner.h>
#include <cppunit/TestResult.h>
#include <cppunit/TestResultCollector.h>
#include <cppunit/extensions/HelperMacros.h>
#include <cppunit/BriefTestProgressListener.h>
#include <cppunit/extensions/TestFactoryRegistry.h>

class RemoteServerTest : public CPPUNIT_NS::TestCase {
    CPPUNIT_TEST_SUITE(RemoteServerTest);
    CPPUNIT_TEST(constructorTest);
    CPPUNIT_TEST(sendRequestTest);
    CPPUNIT_TEST_SUITE_END();
public:
    void setUp() {}
    void tearDown() {}
protected:
    void constructorTest();
    void sendRequestTest();
};

#endif
