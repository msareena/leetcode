cmake_minimum_required(VERSION 3.18)

project(273)

include_directories(${CMAKE_CURRENT_SOURCE_DIR})
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../../source/)

set(SOURCES
    test_problem_${PROJECT_NAME}.cpp)

add_executable(test_problem_${PROJECT_NAME}
               ${SOURCES})

include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG release-1.12.1
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

target_link_libraries(test_problem_${PROJECT_NAME} GTest::gtest_main)
target_link_libraries(test_problem_${PROJECT_NAME} GTest::gmock_main)
target_link_libraries(test_problem_${PROJECT_NAME} leetcode)

enable_testing()
include(GoogleTest)
gtest_discover_tests(test_problem_${PROJECT_NAME})
