# protobuf 3.3.0

set(LIBPROTOBUF_DIR "$ENV{PROTOBUF_ROOT}")
list(APPEND CMAKE_PREFIX_PATH ${LIBPROTOBUF_DIR})
set(Protobuf_SRC_ROOT_FOLDER ${LIBPROTOBUF_DIR})


IF(UNIX)
#set(TEMP_SUFFIXES ${CMAKE_FIND_LIBRARY_SUFFIXES})
#set(CMAKE_FIND_LIBRARY_SUFFIXES ".a")
ENDIF()

find_package(Protobuf REQUIRED)

IF(UNIX)
#set(CMAKE_FIND_LIBRARY_SUFFIXES ${TEMP_SUFFIXES})
#unset(TEMP_SUFFIXES)
ENDIF()

string(ASCII 27 Esc)
message("${Esc}[33m""Protobuf_VERSION              : " ${Protobuf_VERSION} "${Esc}[0m" )
message("${Esc}[33m""Protobuf_INCLUDE_DIR          : " ${Protobuf_INCLUDE_DIR} "${Esc}[0m" )
message("${Esc}[33m""Protobuf_LIBRARY_DEBUG        : " ${Protobuf_LIBRARY_DEBUG} "${Esc}[0m" )
message("${Esc}[33m""Protobuf_LIBRARY_RELEASE      : " ${Protobuf_LIBRARY_RELEASE} "${Esc}[0m" )
message("${Esc}[33m""Protobuf_LITE_LIBRARY_DEBUG   : " ${Protobuf_LITE_LIBRARY_DEBUG} "${Esc}[0m" )
message("${Esc}[33m""Protobuf_LITE_LIBRARY_RELEASE : " ${Protobuf_LITE_LIBRARY_RELEASE} "${Esc}[0m" )
message("${Esc}[33m""Protobuf_PROTOC_EXECUTABLE    : " ${Protobuf_PROTOC_EXECUTABLE} "${Esc}[0m" )
message("${Esc}[33m""Protobuf_LIBRARIES            : " ${Protobuf_LIBRARIES} "${Esc}[0m" )

message("")
