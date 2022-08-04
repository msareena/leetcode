cmake_minimum_required(VERSION 3.18)
project(leetcode_solutions)

include(cmake_gtest.cmake)

function(SetIncludeDirectories)
    include_directories(${CMAKE_CURRENT_SOURCE_DIR})
    include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../source)
endfunction()

function(SetLinkDirectories)
    link_directories($ENV{GTEST_HOME}/lib)
    link_directories(${CMAKE_BINARY_DIR}/source)
endfunction()

function(SetSourceFiles)
    set(SOURCES
        test_sample.cpp
        test_main.cpp
        PARENT_SCOPE)
endfunction()

function(LinkLibraries)
    target_link_libraries(${PROJECT_NAME} gtest_main)
    target_link_libraries(${PROJECT_NAME} gmock_main)
    target_link_libraries(${PROJECT_NAME} pthread)
    target_link_libraries(${PROJECT_NAME} leetcode)
endfunction()

SetIncludeDirectories()
SetSourceFiles()
SetLinkDirectories()
add_executable(${PROJECT_NAME} ${SOURCES})

LinkLibraries()
