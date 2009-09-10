PROJECT(kumonosu_manager)
CMAKE_MINIMUM_REQUIRED(VERSION 2.4.5)

INCLUDE_DIRECTORIES(${CMAKE_SOURCE_DIR})

# ######### Server build #########
# Sources:
SET(kumonosu_manager_SRCS
  ProcedureArguments.cpp
  PingArguments.cpp
  ServerListArguments.cpp
  ServiceListArguments.cpp
  KumonosuManager.cpp
)

IF (THRIFT_FOUND AND Boost_FOUND)
  INCLUDE_DIRECTORIES(${THRIFT_INCLUDE_DIR} ${Boost_INCLUDE_DIRS})
  SET(kumonosu_manager_LIBS
    ${THRIFT_LIBRARIES}
    ${EVENT_LIBRARIES}
    kumonosucore
    kumonosuclient
  )
  ADD_LIBRARY(kumonosu_manager SHARED ${kumonosu_manager_SRCS})
  #ADD_EXECUTABLE(kumonosu_manager ${kumonosu_manager_SRCS})
  TARGET_LINK_LIBRARIES(kumonosu_manager ${kumonosu_manager_LIBS})
ENDIF (THRIFT_FOUND AND Boost_FOUND)

ADD_SUBDIRECTORY(tests/)