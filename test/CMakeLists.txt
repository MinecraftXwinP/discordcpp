cmake_minimum_required(VERSION 3.10)
find_package(GTest)

if ((NOT GTEST_FOUND) OR BUILD_GTEST)
    include(ExternalProject)
    ExternalProject_Add(
        gtest
        GIT_REPOSITORY https://github.com/google/googletest.git
        INSTALL_COMMAND ""
    )
    ExternalProject_Get_Property(gtest source_dir)
    set(GTEST_INCLUDE_DIRS ${source_dir}/googletest/include)
    ExternalProject_Get_Property(gtest binary_dir)
    set(GTEST_LIBRARY_PATH ${binary_dir}/googlemock/gtest/${CMAKE_FIND_LIBRARY_PREFIXES}gtest.a)

    set(GTEST_LIBRARIES googletest)
    add_library(${GTEST_LIBRARIES} UNKNOWN IMPORTED)
    set_property(
        TARGET
        ${GTEST_LIBRARIES}
        PROPERTY IMPORTED_LOCATION
        ${GTEST_LIBRARY_PATH}
    )
    add_dependencies(${GTEST_LIBRARIES} gtest)
endif()

find_package(Threads REQUIRED)

add_executable(
    unit_test
    unit_test.cpp
    unit-rest_api.cpp
    unit-dispatch_payload.cpp
    unit-payload.cpp
    ${DISCORDCPP_PRIVATE_HEADERS}
)

target_link_libraries(
    unit_test
    discordcpp
    ${GTEST_LIBRARIES}
    ${CMAKE_THREAD_LIBS_INIT}
)
target_include_directories(unit_test PRIVATE ${GTEST_INCLUDE_DIRS} ${DISCORDCPP_SRC})

include(GoogleTest)

gtest_discover_tests(unit_test)