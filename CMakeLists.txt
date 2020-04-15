cmake_minimum_required(VERSION 3.16)
project(unions)

set(CMAKE_CXX_STANDARD 17)

set(SRC_DIR "./src")

include_directories(${SRC_DIR})

set(COMMON_SOURCES
    ${SRC_DIR}/utils.cpp
    ${SRC_DIR}/utils.h
    )

add_executable(example01 ${SRC_DIR}/example01.cpp ${COMMON_SOURCES})
add_executable(example02 ${SRC_DIR}/example02.cpp ${COMMON_SOURCES})