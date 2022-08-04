cmake_minimum_required(VERSION 3.18)

project(leetcode)

include_directories(${CMAKE_CURRENT_SOURCE_DIR})

add_subdirectory(273)
add_subdirectory(sample)

add_library(${PROJECT_NAME}
            leetcode.cpp)

target_link_libraries(${PROJECT_NAME} problem_sample)
target_link_libraries(${PROJECT_NAME} problem_273)
