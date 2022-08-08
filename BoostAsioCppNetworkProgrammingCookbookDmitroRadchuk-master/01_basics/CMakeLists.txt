# CMakeLists.txt
# project(tutorial-0)
# cmake_minimum_required(VERSION 3.7)
# set(CMAKE_CXX_STANDARD 14)

# set(BOOST_ROOT /usr/local/install/boost_1_62_0) #设置boost库搜索路径
# set(Boost_NO_SYSTEM_PATHS ON) # 只搜索上语句设置的搜索路径

# find_package(Boost)


# include_directories(${Boost_INCLUDE_DIRS})
    
# MESSAGE( STATUS "Boost_INCLUDE_DIRS = ${Boost_INCLUDE_DIRS}.")
# MESSAGE( STATUS "Boost_LIBRARIES = ${Boost_LIBRARIES}.")
# MESSAGE( STATUS "Boost_LIB_VERSION = ${Boost_LIB_VERSION}.")

# add_executable(active_socket_udp ./active_socket_udp.cpp)
# target_link_libraries (active_socket_udp ${Boost_LIBRARIES})

# target_link_libraries(active_socket_ud  -lpthread -lm)
    


CMAKE_MINIMUM_REQUIRED(VERSION 2.80 )
PROJECT(active_socket_udp)
# SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/executable)

message(“BOOST_LIBRARYDIR =”${BOOST_LIBRARYDIR})

FIND_PACKAGE(Boost REQUIRED )
FIND_PACKAGE(Threads REQUIRED)

ADD_EXECUTABLE(active_socket_udp active_socket_udp.cpp )

target_link_libraries (${PROJECT_NAME} ${Boost_LIBRARIES}) #链接boost
target_link_libraries(${PROJECT_NAME} ${CMAKE_THREAD_LIBS_INIT}) #链接threads

