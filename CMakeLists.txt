cmake_minimum_required(VERSION 3.16)

project (scan_util)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Werror -std=c++17")
# set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -stdc++fc")

include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}/include
    )
    
set(SOURCES_SCAN_UTIL
    ${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/checker.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/timework.cpp)

add_executable(scan_util ${SOURCES_SCAN_UTIL})