ENABLE_TESTING()
# ########## Project setup ##########
PROJECT(kumonosu)
CMAKE_MINIMUM_REQUIRED(VERSION 2.4.5)

# ######### General setup ##########
INCLUDE_DIRECTORIES(${CMAKE_SOURCE_DIR})

SET(Thrift_DIR ${CMAKE_SOURCE_DIR})
SET(Event_DIR ${CMAKE_SOURCE_DIR})

FIND_PACKAGE(Thrift)
FIND_PACKAGE(Boost)
FIND_PACKAGE(Event)

SET(kumonosu_core_library_SRCS
  InternalMessageProcessor.cpp
  LocalRequestManager.cpp
  LocalRequestManagerHandler.cpp
  OutgoingClient.cpp
  RemoteRequestManager.cpp
  RemoteRequestManagerHandler.cpp
  RemoteServer.cpp
  RequestQueue.cpp
  Server.cpp
  kumonosu_server_constants.cpp
  kumonosu_server_types.cpp
)

IF (THRIFT_FOUND AND Boost_FOUND AND EVENT_FOUND)
  INCLUDE_DIRECTORIES(${THRIFT_INCLUDE_DIR} ${Boost_INCLUDE_DIRS} ${EVENT_INCLUDE_DIRS})
  SET(core_library_list
    ${THRIFT_LIBRARIES}
    ${EVENT_LIBRARIES}
  )

  ADD_LIBRARY(kumonosucore SHARED ${kumonosu_core_library_SRCS})
  TARGET_LINK_LIBRARIES(kumonosucore ${core_library_list})
ENDIF (THRIFT_FOUND AND Boost_FOUND AND EVENT_FOUND)

ADD_SUBDIRECTORY(server/)
ADD_SUBDIRECTORY(clientlib/)
ADD_SUBDIRECTORY(manager/)
ADD_SUBDIRECTORY(tests/)
# add install target:
#INSTALL(TARGETS src DESTINATION bin)
