/*
** OutgoingClientTest.h
** 
** Made by Matthew Brace
** Login   <mbrace@godwin.lan>
** 
** Started on  Sat Aug  1 22:48:18 2009 Matthew Brace
** Last update Sat Aug  1 22:48:18 2009 Matthew Brace
*/

#ifndef   	OUTGOINGCLIENTTEST_H_
#define   	OUTGOINGCLIENTTEST_H_

#include <cppunit/TestRunner.h>
#include <cppunit/TestResult.h>
#include <cppunit/TestResultCollector.h>
#include <cppunit/extensions/HelperMacros.h>
#include <cppunit/BriefTestProgressListener.h>
#include <cppunit/extensions/TestFactoryRegistry.h>

class OutgoingClientTest : public CPPUNIT_NS::TestCase {
    CPPUNIT_TEST_SUITE(OutgoingClientTest);
    CPPUNIT_TEST(constructorTest);
    CPPUNIT_TEST(setOutgoingQueueTest);
    CPPUNIT_TEST(addServerTest);
    CPPUNIT_TEST(removeServerTest);
    CPPUNIT_TEST(runTest);
    CPPUNIT_TEST(processOutgoingQueueTest);
    CPPUNIT_TEST_SUITE_END();
public:
    void setUp(void) {}
    void tearDown(void) {}
protected:
    void constructorTest();
    void setOutgoingQueueTest();
    void addServerTest();
    void removeServerTest();
    void runTest();
    void processOutgoingQueueTest();
};


#endif 	    /* !OUTGOINGCLIENTTEST_H_ */
