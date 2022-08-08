cmake_minimum_required(VERSION 3.0)
project(dm01)


SET(CMAKE_MODULE_PATH  ${PROJECT_SOURCE_DIR}/cmake  ${CMAKE_MODULE_PATH})

# SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)
# set(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/lib)

message(STATUS   "CMAKE_MODULE_PATH ==  "        "${CMAKE_MODULE_PATH}")
find_package(Asio REQUIRED)
message(STATUS  ${ASIO_FOUND})
include_directories(${Asio_INCLUDE_DIR})


add_library(hello  dm01.cpp)

SET_TARGET_PROPERTIES(hello PROPERTIES CLEAN_DIRECT_OUTPUT 1)
# SET_TARGET_PROPERTIES(hello_static PROPERTIES CLEAN_DIRECT_OUTPUT 1)
SET_TARGET_PROPERTIES(hello PROPERTIES VERSION 1.2 SOVERSION 1)

include_directories()
add_executable(${PROJECT_NAME}  dm01.cpp)
target_link_libraries(${PROJECT_NAME}  -lpthread -lm)





# INSTALL(TARGETS ${PROJECT_NAME}
#                     RUNTIME DESTINATION bin
#                     LIBRARY DESTINATION lib
#                     ARCHIVE DESTINATION libstatic
# )

# INSTALL(FILES COPYRIGHT README DESTINATION share/doc/cmake/t2)
# INSTALL(PROGRAMS run.sh DESTINATION bin)











