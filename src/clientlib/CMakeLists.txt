PROJECT(kumonosu_client_lib)
CMAKE_MINIMUM_REQUIRED(VERSION 2.4.5)

INCLUDE_DIRECTORIES(${CMAKE_SOURCE_DIR})

# ######### Server build #########
# Sources:
SET(kumonosu_client_library_SRCS
  Client.cpp
  MethodMap.h
)

IF (THRIFT_FOUND AND Boost_FOUND)
  INCLUDE_DIRECTORIES(${THRIFT_INCLUDE_DIR} ${Boost_INCLUDE_DIRS})
  SET(client_library_list
    ${THRIFT_LIBRARIES}
    ${EVENT_LIBRARIES}
    kumonosucore
  )
  ADD_LIBRARY(kumonosuclient SHARED ${kumonosu_client_library_SRCS})
  TARGET_LINK_LIBRARIES(kumonosuclient ${client_library_list})
ENDIF (THRIFT_FOUND AND Boost_FOUND)

ADD_SUBDIRECTORY(tests/)