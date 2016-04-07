cmake_minimum_required(VERSION 3.2)

project(chessboard)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU" OR "${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
    add_definitions(-std=c++14 -Wall -Wpedantic -Werror)
    add_definitions(-fno-exceptions -fno-rtti)
    if ("${CMAKE_BUILD_TYPE}" STREQUAL "Debug")
        add_definitions(-O0) # -g is added automatically
    elseif("${CMAKE_BUILD_TYPE}" STREQUAL "Release")
        add_definitions(-s) # -O3 is added automatically
    endif()
endif()

find_package(Qt5 REQUIRED COMPONENTS Quick)

add_subdirectory(src)
