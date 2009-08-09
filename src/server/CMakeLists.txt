PROJECT(kumonosu_server)
CMAKE_MINIMUM_REQUIRED(VERSION 2.4.5)

INCLUDE_DIRECTORIES(${CMAKE_SOURCE_DIR})

# ######### Server build #########
# Sources:
SET(kumonosu_executable_server_SRCS
  main.cpp
  ../InternalMessageProcessor.cpp
  ../kumonosu_server_constants.cpp
  ../kumonosu_server_types.cpp
  ../LocalRequestManager.cpp
  ../LocalRequestManagerHandler.cpp
  ../OutgoingClient.cpp
  ../RemoteRequestManager.cpp
  ../RemoteRequestManagerHandler.cpp
  ../RemoteServer.cpp
  ../RequestQueue.cpp
)

IF (THRIFT_FOUND AND Boost_FOUND)
  INCLUDE_DIRECTORIES(${THRIFT_INCLUDE_DIR} ${Boost_INCLUDE_DIRS})
  ADD_EXECUTABLE(kumonosu_server ${kumonosu_executable_server_SRCS})
  TARGET_LINK_LIBRARIES(kumonosu_server ${THRIFT_LIBRARIES} ${EVENT_LIBRARIES})
ENDIF (THRIFT_FOUND AND Boost_FOUND)