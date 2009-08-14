/*
** MessageProcessorTest.h
** 
** Made by Matthew Brace
** Login   <mbrace@godwin.lan>
** 
** Started on  Thu Aug 13 00:16:21 CDT 2009 Matthew Brace
** Last update Thu Aug 13 21:53:54 CDT 2009 Matthew Brace
*/

#ifndef   	MESSAGEPROCESSORTEST_H_
#define   	MESSAGEPROCESSORTEST_H_

#include <cppunit/TestRunner.h>
#include <cppunit/TestResult.h>
#include <cppunit/TestResultCollector.h>
#include <cppunit/extensions/HelperMacros.h>
#include <cppunit/BriefTestProgressListener.h>
#include <cppunit/extensions/TestFactoryRegistry.h>

class MessageProcessorTest : public CPPUNIT_NS::TestCase {
    CPPUNIT_TEST_SUITE(MessageProcessorTest);
    CPPUNIT_TEST(constructorTest);
    CPPUNIT_TEST(setClientTest);
    CPPUNIT_TEST(setMethodCallbackTest);
    CPPUNIT_TEST(removeMethodCallbackTest);
    CPPUNIT_TEST(processPendingItemsTest);
    CPPUNIT_TEST_SUITE_END();
public:
    void setUp(void) {}
    void tearDown(void) {}
protected:
    void constructorTest();
    void setClientTest();
    void setMethodCallbackTest();
    void removeMethodCallbackTest();
    void processPendingItemsTest();
};

#endif 	    /* !MESSAGEPROCESSORTEST_H_ */
