# fmt 7.1.2

set(LIBFMT_DIR "$ENV{FMT_ROOT}")
list(APPEND CMAKE_PREFIX_PATH ${LIBFMT_DIR})
set(fmt_SRC_ROOT_FOLDER ${LIBFMT_DIR})


IF(UNIX)
#set(TEMP_SUFFIXES ${CMAKE_FIND_LIBRARY_SUFFIXES})
#set(CMAKE_FIND_LIBRARY_SUFFIXES ".a")
ENDIF()

find_package(fmt REQUIRED)


IF(UNIX)
#set(CMAKE_FIND_LIBRARY_SUFFIXES ${TEMP_SUFFIXES})
#unset(TEMP_SUFFIXES)
ENDIF()

string(ASCII 27 Esc)
message( "${Esc}[33m" "fmt_VERSION" "              : " "${fmt_VERSION}" "${Esc}[0m" )
message( "${Esc}[33m" "fmt_INCLUDE_DIR" "          : " "${fmt_INCLUDE_DIR}" "${Esc}[0m" )
message( "${Esc}[33m" "fmt_LIBRARY_DEBUG" "        : " "${fmt_LIBRARY_DEBUG}" "${Esc}[0m" )
message( "${Esc}[33m" "fmt_LIBRARY_RELEASE" "      : " "${fmt_LIBRARY_RELEASE}" "${Esc}[0m" )
message( "${Esc}[33m" "fmt_LITE_LIBRARY_DEBUG" "   : " "${fmt_LITE_LIBRARY_DEBUG}" "${Esc}[0m" )
message( "${Esc}[33m" "fmt_LITE_LIBRARY_RELEASE" " : " "${fmt_LITE_LIBRARY_RELEASE}" "${Esc}[0m" )
message( "${Esc}[33m" "fmt_PROTOC_EXECUTABLE" "    : " "${fmt_PROTOC_EXECUTABLE}" "${Esc}[0m" )
message( "${Esc}[33m" "fmt_LIBRARIES" "            : " "${fmt_LIBRARIES}" "${Esc}[0m" )

