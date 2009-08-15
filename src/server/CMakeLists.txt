PROJECT(kumonosu_server)
CMAKE_MINIMUM_REQUIRED(VERSION 2.4.5)

INCLUDE_DIRECTORIES(${CMAKE_SOURCE_DIR})

# ######### Server build #########
# Sources:
SET(kumonosu_executable_server_SRCS
  main.cpp
)

IF (THRIFT_FOUND AND Boost_FOUND)
  INCLUDE_DIRECTORIES(${THRIFT_INCLUDE_DIR} ${Boost_INCLUDE_DIRS})
  SET(kumonosu_executable_libraries
    ${THRIFT_LIBRARIES}
    ${EVENT_LIBRARIES}
    kumonosucore
  )
  ADD_EXECUTABLE(kumonosu_server ${kumonosu_executable_server_SRCS})
  TARGET_LINK_LIBRARIES(kumonosu_server ${kumonosu_executable_libraries})
ENDIF (THRIFT_FOUND AND Boost_FOUND)