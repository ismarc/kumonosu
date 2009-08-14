/*
** CallbackTest.h
** 
** Made by Matthew Brace
** Login   <mbrace@godwin.lan>
** 
** Started on  Wed Aug 12 23:53:14 2009 Matthew Brace
** Last update Wed Aug 12 23:53:14 2009 Matthew Brace
*/

#ifndef   	CALLBACKTEST_H_
#define   	CALLBACKTEST_H_

#include <cppunit/TestRunner.h>
#include <cppunit/TestResult.h>
#include <cppunit/TestResultCollector.h>
#include <cppunit/extensions/HelperMacros.h>
#include <cppunit/BriefTestProgressListener.h>
#include <cppunit/extensions/TestFactoryRegistry.h>

class CallbackTest : public CPPUNIT_NS::TestCase {
    CPPUNIT_TEST_SUITE(CallbackTest);
    CPPUNIT_TEST(constructorTest);
    CPPUNIT_TEST(executeTest);
    CPPUNIT_TEST_SUITE_END();
public:
    void setUp(void) {}
    void tearDown(void) {}
protected:
    void constructorTest();
    void executeTest();
};


#endif 	    /* !CALLBACKTEST_H_ */
