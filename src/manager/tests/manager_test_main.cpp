#include "KumonosuManagerTest.h"

CPPUNIT_TEST_SUITE_REGISTRATION(KumonosuManagerTest);

int main(int ac, char **av)
{
    CPPUNIT_NS::TestResult controller;
    CPPUNIT_NS::TestResultCollector result;
    controller.addListener(&result);
    CPPUNIT_NS::BriefTestProgressListener briefProgress;
    controller.addListener(&briefProgress);
    CPPUNIT_NS::TestRunner runner;
    runner.addTest(CPPUNIT_NS::TestFactoryRegistry::getRegistry().makeTest());
    runner.run(controller);

    return result.wasSuccessful() ? 0 : 1;
}
