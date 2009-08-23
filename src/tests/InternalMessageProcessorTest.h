/*
** InternalMessageProcessorTest.h
** 
** Made by Matthew Brace
** Login   <mbrace@godwin.lan>
** 
** Started on  Thu Jul 30 23:48:42 2009 Matthew Brace
** Last update Thu Jul 30 23:48:42 2009 Matthew Brace
*/

#ifndef   	INTERNALMESSAGEPROCESSORTEST_H_
#define   	INTERNALMESSAGEPROCESSORTEST_H_

#include <cppunit/TestRunner.h>
#include <cppunit/TestResult.h>
#include <cppunit/TestResultCollector.h>
#include <cppunit/extensions/HelperMacros.h>
#include <cppunit/BriefTestProgressListener.h>
#include <cppunit/extensions/TestFactoryRegistry.h>

void* runProcessor(void *arg);

class InternalMessageProcessorTest : public CPPUNIT_NS::TestCase {
    CPPUNIT_TEST_SUITE(InternalMessageProcessorTest);
    CPPUNIT_TEST(constructorTest);
    CPPUNIT_TEST(setInternalQueueTest);
    CPPUNIT_TEST(runTest);
    CPPUNIT_TEST(processItemTest);
    CPPUNIT_TEST_SUITE_END();
public:
    void setUp(void) {}
    void tearDown(void) {}
protected:
    void constructorTest();
    void setInternalQueueTest();
    void runTest();
    void processItemTest();
    void getServerListTest();
};

#endif 	    /* !INTERNALMESSAGEPROCESSORTEST_H_ */
