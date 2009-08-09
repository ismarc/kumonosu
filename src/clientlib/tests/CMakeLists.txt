ENABLE_TESTING()
PROJECT(kumonosu_tests)
CMAKE_MINIMUM_REQUIRED(VERSION 2.4.5)

INCLUDE_DIRECTORIES(${CMAKE_SOURCE_DIR})

# Sources:
SET(client_test_executable_SRCS
  client_test_main.cpp
  ../Client.cpp
  ../../LocalRequestManager.cpp
  ../../LocalRequestManagerHandler.cpp
  ../../RequestQueue.cpp
  ../../kumonosu_server_types.cpp
  ClientTest.cpp
)

SET(CppUnit_DIR /home/ismarc/kumonosu/core/src/)
FIND_PACKAGE(CppUnit)

IF (CPPUNIT_FOUND AND THRIFT_FOUND AND Boost_FOUND)
  INCLUDE_DIRECTORIES(${CPPUNIT_INCLUDE_DIR} ${THRIFT_INCLUDE_DIR})
  # Client Test
  ADD_EXECUTABLE(client_test ${client_test_executable_SRCS})
  TARGET_LINK_LIBRARIES(client_test ${CPPUNIT_LIBRARY} ${THRIFT_LIBRARY})
ENDIF (CPPUNIT_FOUND AND THRIFT_FOUND AND Boost_FOUND)

ADD_TEST(client_test client_test)

