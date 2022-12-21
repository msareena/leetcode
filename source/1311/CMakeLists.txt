cmake_minimum_required(VERSION 3.24)

project(problem_1311)

include_directories(${CMAKE_CURRENT_SOURCE_DIR})

set(COMMON_SOURCES
    ${PROJECT_NAME}.cpp)

set(MAIN_SOURCES
    ${COMMON_SOURCES}
    main.cpp)

set(TEST_SOURCES
    ${COMMON_SOURCES}
    ${PROJECT_NAME}_test.cpp)

add_executable(${PROJECT_NAME} ${MAIN_SOURCES})

add_executable(test_${PROJECT_NAME} ${TEST_SOURCES})
find_package(GTest CONFIG REQUIRED)
target_link_libraries(test_${PROJECT_NAME} GTest::gtest_main)

enable_testing()
include(GoogleTest)
gtest_discover_tests(test_${PROJECT_NAME})