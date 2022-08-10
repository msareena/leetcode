cmake_minimum_required(VERSION 3.18)

project(273)

include_directories(${CMAKE_CURRENT_SOURCE_DIR})

set(SOURCES
    problem_${PROJECT_NAME}.cpp)

add_library(problem_${PROJECT_NAME}
            ${SOURCES})
