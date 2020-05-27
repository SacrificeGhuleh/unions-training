cmake_minimum_required(VERSION 3.10)
project(unions)
set(CMAKE_CXX_STANDARD 17)

set(SRC_DIR "./src")

include_directories(${SRC_DIR})
include_directories(${COMMON_LIB_PATH})
add_subdirectory(${COMMON_LIB_PATH} "./common" EXCLUDE_FROM_ALL)

add_executable(${PROJECT_NAME}_example01 ${SRC_DIR}/example01.cpp ${COMMON_SOURCES})
add_executable(${PROJECT_NAME}_example02 ${SRC_DIR}/example02.cpp ${COMMON_SOURCES})
add_executable(${PROJECT_NAME}_example03 ${SRC_DIR}/example03.cpp ${COMMON_SOURCES})
