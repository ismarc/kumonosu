ENABLE_TESTING()
PROJECT(kumonosu_tests)
CMAKE_MINIMUM_REQUIRED(VERSION 2.4.5)

INCLUDE_DIRECTORIES(${CMAKE_SOURCE_DIR})

# Sources:
SET(manager_test_SRCS
  manager_test_main.cpp
  ../ProcedureArguments.cpp
  ../PingArguments.cpp
  ../ServerListArguments.cpp
  ../ServiceListArguments.cpp
  ../KumonosuManager.cpp
  KumonosuManagerTest.cpp
)

SET(CppUnit_DIR /home/ismarc/kumonosu/core/src/)
FIND_PACKAGE(CppUnit)

IF (CPPUNIT_FOUND AND THRIFT_FOUND AND Boost_FOUND)
  INCLUDE_DIRECTORIES(${CPPUNIT_INCLUDE_DIR} ${THRIFT_INCLUDE_DIR})
  SET(test_libraries
    ${CPPUNIT_LIBRARY}
    ${THRIFT_LIBRARY}
    kumonosuclient
  )
  # Kumonosu Manager Test
  ADD_EXECUTABLE(manager_test ${manager_test_SRCS})
  TARGET_LINK_LIBRARIES(manager_test ${test_libraries})
ENDIF (CPPUNIT_FOUND AND THRIFT_FOUND AND Boost_FOUND)

ADD_TEST("manager::KumonosuManager" manager_test)

