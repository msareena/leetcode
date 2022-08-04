cmake_minimum_required(VERSION 3.18)

project(leetcode)

include_directories(${CMAKE_CURRENT_SOURCE_DIR})

set(SOURCES
    sample.cpp)

add_library(${PROJECT_NAME}
            ${SOURCES})