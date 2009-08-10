/*
** ClientTest.h
** 
** Made by Matthew Brace
** Login   <mbrace@godwin.lan>
** 
** Started on  Wed Aug  5 02:55:17 2009 Matthew Brace
** Last update Wed Aug  5 02:55:17 2009 Matthew Brace
*/

#ifndef   	CLIENTTEST_H_
#define   	CLIENTTEST_H_

#include <cppunit/TestRunner.h>
#include <cppunit/TestResult.h>
#include <cppunit/TestResultCollector.h>
#include <cppunit/extensions/HelperMacros.h>
#include <cppunit/BriefTestProgressListener.h>
#include <cppunit/extensions/TestFactoryRegistry.h>

class ClientTest : public CPPUNIT_NS::TestCase {
    CPPUNIT_TEST_SUITE(ClientTest);
    CPPUNIT_TEST(constructorTest);
    CPPUNIT_TEST(setServerAddressTest);
    CPPUNIT_TEST(setServerPortTest);
    CPPUNIT_TEST(connectTest);
    CPPUNIT_TEST(sendRequestTest);
    CPPUNIT_TEST(sendLocalRequestTest);
    CPPUNIT_TEST(getNextPendingItemTest);
    //CPPUNIT_TEST(getPendingItemsTest);
    CPPUNIT_TEST_SUITE_END();
public:
    void setUp(void) {}
    void tearDwon(void) {}
protected:
    void constructorTest();
    void setServerAddressTest();
    void setServerPortTest();
    void connectTest();
    void sendRequestTest();
    void sendLocalRequestTest();
    void getNextPendingItemTest();
    void getPendingItemsTest();
};

#endif 	    /* !CLIENTTEST_H_ */
