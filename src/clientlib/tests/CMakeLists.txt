ENABLE_TESTING()
PROJECT(kumonosu_tests)
CMAKE_MINIMUM_REQUIRED(VERSION 2.4.5)

INCLUDE_DIRECTORIES(${CMAKE_SOURCE_DIR})

# Sources:
SET(client_test_executable_SRCS
  client_test_main.cpp
  ClientTest.cpp
)

SET(callback_test_executable_SRCS
  callback_test_main.cpp
  CallbackTest.cpp
)

SET(message_processor_executable_SRCS
  message_processor_test_main.cpp
  MessageProcessorTest.cpp
)

SET(CppUnit_DIR /home/ismarc/kumonosu/core/src/)
FIND_PACKAGE(CppUnit)

IF (CPPUNIT_FOUND AND THRIFT_FOUND AND Boost_FOUND)
  INCLUDE_DIRECTORIES(${CPPUNIT_INCLUDE_DIR} ${THRIFT_INCLUDE_DIR})
  SET(library_list
    kumonosuclient
    ${THRIFT_LIBRARY}
    ${CPPUNIT_LIBRARY}
  )
  # Client Test
  ADD_EXECUTABLE(client_test ${client_test_executable_SRCS})
  TARGET_LINK_LIBRARIES(client_test ${library_list})
  # Callback Test
  ADD_EXECUTABLE(callback_test ${callback_test_executable_SRCS})
  TARGET_LINK_LIBRARIES(callback_test ${library_list})
  # Message Processor Test
  ADD_EXECUTABLE(message_processor_test ${message_processor_executable_SRCS})
  TARGET_LINK_LIBRARIES(message_processor_test ${library_list})
ENDIF (CPPUNIT_FOUND AND THRIFT_FOUND AND Boost_FOUND)

ADD_TEST(client_test client_test)
ADD_TEST(callback_test callback_test)
ADD_TEST(message_processor_test message_processor_test)