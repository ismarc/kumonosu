/*
** KumonosuManagerTest.h
** 
** Made by Matthew Brace
** Login   <mbrace@godwin.lan>
** 
** Started on  Sun Aug 23 21:38:48 2009 Matthew Brace
** Last update Sun Aug 23 21:38:48 2009 Matthew Brace
*/

#ifndef   	KUMONOSUMANAGERTEST_H_
#define   	KUMONOSUMANAGERTEST_H_

#include <cppunit/TestRunner.h>
#include <cppunit/TestResult.h>
#include <cppunit/TestResultCollector.h>
#include <cppunit/extensions/HelperMacros.h>
#include <cppunit/BriefTestProgressListener.h>
#include <cppunit/extensions/TestFactoryRegistry.h>

class KumonosuManagerTest : public CPPUNIT_NS::TestCase {
    CPPUNIT_TEST_SUITE(KumonosuManagerTest);
    CPPUNIT_TEST(constructorTest);
    CPPUNIT_TEST(runTest);
    CPPUNIT_TEST(runWithClientTest);
    CPPUNIT_TEST(methodNotFoundTest);
    CPPUNIT_TEST(pingTest);
    CPPUNIT_TEST(pongTest);
    CPPUNIT_TEST(getServerListTest);
    CPPUNIT_TEST(getServerListResponseTest);
    CPPUNIT_TEST(getServiceListTest);
    CPPUNIT_TEST(getServiceListResponseTest);
    CPPUNIT_TEST_SUITE_END();
public:
    void setUp(void) {}
    void tearDown(void) {}
protected:
    void constructorTest();
    void runTest();
    void runWithClientTest();
    void methodNotFoundTest();
    void pingTest();
    void pongTest();
    void getServerListTest();
    void getServerListResponseTest();
    void getServiceListTest();
    void getServiceListResponseTest();
};


#endif 	    /* !KUMONOSUMANAGERTEST_H_ */
