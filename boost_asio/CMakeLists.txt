CMAKE_MINIMUM_REQUIRED(VERSION 2.80 )
PROJECT(active_socket_udp)
# SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/executable)





# set(PACKAGE_VERSION 1.73.0)
# if(PACKAGE_VERSION VERSION_LESS PACKAGE_FIND_VERSION)
#   set(PACKAGE_VERSION_COMPATIBLE FALSE)
# else()
#   set(PACKAGE_VERSION_COMPATIBLE TRUE)
#   if(PACKAGE_FIND_VERSION STREQUAL PACKAGE_VERSION)
#     set(PACKAGE_VERSION_EXACT TRUE)
#   endif()
# endif()



SET(CMAKE_MODULE_PATH  ${PROJECT_SOURCE_DIR}/cmake ${CMAKE_MODULE_PATH})

message(“BOOST_LIBRARYDIR =”${BOOST_LIBRARYDIR})





FIND_PACKAGE(Boost REQUIRED )
FIND_PACKAGE(Threads REQUIRED)

ADD_EXECUTABLE(demo01 src/demo01.cpp )
target_link_libraries (demo01 ${Boost_LIBRARIES}) #链接boost
target_link_libraries(demo01 ${CMAKE_THREAD_LIBS_INIT}) #链接threads


ADD_EXECUTABLE(demo02 src/demo02.cpp )
target_link_libraries (demo02 ${Boost_LIBRARIES}) #链接boost
target_link_libraries(demo02 ${CMAKE_THREAD_LIBS_INIT}) #链接threads

ADD_EXECUTABLE(demo03 src/demo03.cpp )
target_link_libraries (demo03 ${Boost_LIBRARIES}) #链接boost
target_link_libraries(demo03 ${CMAKE_THREAD_LIBS_INIT}) #链接threads

ADD_EXECUTABLE(demo04 src/demo04.cpp )
target_link_libraries (demo04 ${Boost_LIBRARIES}) #链接boost
target_link_libraries(demo04 ${CMAKE_THREAD_LIBS_INIT}) #链接threads

ADD_EXECUTABLE(demo05 src/demo05.cpp )
target_link_libraries (demo05 ${Boost_LIBRARIES}) #链接boost
target_link_libraries(demo05 ${CMAKE_THREAD_LIBS_INIT}) #链接threads

# ADD_EXECUTABLE(demo06 src/demo06.cpp )
# target_link_libraries (demo06 ${Boost_LIBRARIES}) #链接boost
# target_link_libraries(demo06 ${CMAKE_THREAD_LIBS_INIT}) #链接threads

# ADD_EXECUTABLE(async_tcp_echo_server  src/async_tcp_echo_server.cpp )
# target_link_libraries (async_tcp_echo_server ${Boost_LIBRARIES}) #链接boost
# target_link_libraries(async_tcp_echo_server ${CMAKE_THREAD_LIBS_INIT}) #链接threads

# ADD_EXECUTABLE(blocking_tcp_echo_client src/blocking_tcp_echo_client.cpp )
# target_link_libraries (blocking_tcp_echo_client ${Boost_LIBRARIES}) #链接boost
# target_link_libraries(blocking_tcp_echo_client ${CMAKE_THREAD_LIBS_INIT}) #链接threads