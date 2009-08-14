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

SET(callback_test_executable_SRCS
  callback_test_main.cpp
  ../Callback.cpp
  ../../kumonosu_server_types.cpp
  CallbackTest.cpp
)

SET(message_processor_executable_SRCS
  message_processor_test_main.cpp
  ../MessageProcessor.cpp
  ../Callback.cpp
  ../Client.cpp
  ../../LocalRequestManager.cpp
  ../../LocalRequestManagerHandler.cpp
  ../../RequestQueue.cpp
  ../../kumonosu_server_types.cpp
  MessageProcessorTest.cpp
)

SET(CppUnit_DIR /home/ismarc/kumonosu/core/src/)
FIND_PACKAGE(CppUnit)

IF (CPPUNIT_FOUND AND THRIFT_FOUND AND Boost_FOUND)
  INCLUDE_DIRECTORIES(${CPPUNIT_INCLUDE_DIR} ${THRIFT_INCLUDE_DIR})
  # Client Test
  ADD_EXECUTABLE(client_test ${client_test_executable_SRCS})
  TARGET_LINK_LIBRARIES(client_test ${CPPUNIT_LIBRARY} ${THRIFT_LIBRARY})
  # Callback Test
  ADD_EXECUTABLE(callback_test ${callback_test_executable_SRCS})
  TARGET_LINK_LIBRARIES(callback_test ${CPPUNIT_LIBRARY} ${THRIFT_LIBRARY})
  # Message Processor Test
  ADD_EXECUTABLE(message_processor_test ${message_processor_executable_SRCS})
  TARGET_LINK_LIBRARIES(message_processor_test ${CPPUNIT_LIBRARY} ${THRIFT_LIBRARY})
ENDIF (CPPUNIT_FOUND AND THRIFT_FOUND AND Boost_FOUND)

ADD_TEST(client_test client_test)
ADD_TEST(callback_test callback_test)
ADD_TEST(message_processor_test message_processor_test)