ENABLE_TESTING()
PROJECT(kumonosu_tests)
CMAKE_MINIMUM_REQUIRED(VERSION 2.4.5)

INCLUDE_DIRECTORIES(${CMAKE_SOURCE_DIR})

# Sources:
SET(request_queue_test_executable_SRCS
  request_queue_main.cpp
  ../RequestQueue.cpp
  RequestQueueTest.cpp
)

SET(rrmh_test_executable_SRCS
  rrmh_main.cpp
  ../RemoteRequestManagerHandler.cpp
  ../RequestQueue.cpp
  RemoteRequestManagerHandlerTest.cpp
)

SET(lrmh_test_executable_SRCS
  lrmh_main.cpp
  ../LocalRequestManagerHandler.cpp
  ../RequestQueue.cpp
  LocalRequestManagerHandlerTest.cpp
)

SET(remote_server_test_executable_SRCS
  remote_server_main.cpp
  ../RequestQueue.cpp
  ../RemoteRequestManagerHandler.cpp
  ../RemoteRequestManager.cpp
  ../kumonosu_server_types.cpp
  ../RemoteServer.cpp
  RemoteServerTest.cpp
)

SET(imp_test_executable_SRCS
  imp_test_main.cpp
  ../InternalMessageProcessor.cpp
  ../RequestQueue.cpp
  InternalMessageProcessorTest.cpp
)

SET(outgoing_client_executable_SRCS
  outgoing_client_main.cpp
  ../kumonosu_server_types.cpp
  ../OutgoingClient.cpp
  ../RemoteServer.cpp
  ../RemoteRequestManager.cpp
  ../RemoteRequestManagerHandler.cpp
  ../RequestQueue.cpp
  OutgoingClientTest.cpp
)

SET(CppUnit_DIR /home/ismarc/kumonosu/core/src/)
FIND_PACKAGE(CppUnit)

IF (CPPUNIT_FOUND AND THRIFT_FOUND AND Boost_FOUND)
  INCLUDE_DIRECTORIES(${CPPUNIT_INCLUDE_DIR} ${THRIFT_INCLUDE_DIR})
  # Request Queue Test
  ADD_EXECUTABLE(request_queue_test ${request_queue_test_executable_SRCS})
  TARGET_LINK_LIBRARIES(request_queue_test ${CPPUNIT_LIBRARY} ${THRIFT_LIBRARY})
  # Remote Request Manager Handler Test
  ADD_EXECUTABLE(rrmh_test ${rrmh_test_executable_SRCS})
  TARGET_LINK_LIBRARIES(rrmh_test ${CPPUNIT_LIBRARY})
  # Local Request Manager Handler Test
  ADD_EXECUTABLE(lrmh_test ${lrmh_test_executable_SRCS})
  TARGET_LINK_LIBRARIES(lrmh_test ${CPPUNIT_LIBRARY})
  # Remote Server Test
  ADD_EXECUTABLE(remote_server_test ${remote_server_test_executable_SRCS})
  TARGET_LINK_LIBRARIES(remote_server_test ${CPPUNIT_LIBRARY} ${THRIFT_LIBRARY})
  # Internal Message Processor Test
  ADD_EXECUTABLE(imp_test ${imp_test_executable_SRCS})
  TARGET_LINK_LIBRARIES(imp_test ${CPPUNIT_LIBRARY} ${THRIFT_LIBRARY})
  # Outgoing Client Test
  ADD_EXECUTABLE(outgoing_client_test ${outgoing_client_executable_SRCS})
  TARGET_LINK_LIBRARIES(outgoing_client_test ${CPPUNIT_LIBRARY} ${THRIFT_LIBRARY})
ENDIF (CPPUNIT_FOUND AND THRIFT_FOUND AND Boost_FOUND)

ADD_TEST(request_queue_test request_queue_test)
ADD_TEST(rrmh_test rrmh_test)
ADD_TEST(lrmh_test lrmh_test)
ADD_TEST(remote_server_test remote_server_test)
ADD_TEST(imp_test imp_test)
ADD_TEST(outgoing_client_test outgoing_client_test)