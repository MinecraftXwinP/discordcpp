cmake_minimum_required(VERSION 3.10)

include(GoogleTest)
find_package(GTest REQUIRED)

add_executable(unit_test unit_test.cpp)

target_link_libraries(unit_test ${GTEST_LIBRARIES})
target_include_directories(unit_test PRIVATE ${GTEST_INCLUDE_DIRS})
gtest_discover_tests(unit_test)