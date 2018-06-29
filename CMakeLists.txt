cmake_minimum_required(VERSION 2.8)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake)

find_package(Boost COMPONENTS system REQUIRED)
find_package(nlohmann_json)
find_package(OpenSSL REQUIRED)
find_package(Threads REQUIRED)


set(DISCORDCPP_SRC ${CMAKE_CURRENT_SOURCE_DIR}/src)

add_library(
    discordcpp
    src/client.cpp
    src/gateway.cpp
    src/rest_api.cpp
    src/payload.hpp
    src/payload.cpp
    src/dispatch_payload.hpp
    src/dispatch_payload.cpp
)

target_link_libraries(
	discordcpp
	${Boost_SYSTEM_LIBRARIES}
	${OPENSSL_LIBRARIES}
	${CMAKE_THREAD_LIBS_INIT}
)

target_include_directories(
    discordcpp PUBLIC include
    ${Boost_INCLUDE_DIRS}
)

if(NOT ${nlohmann_json_INCLUDE_DIRS})
    include(ExternalProject)
    ExternalProject_Add(
        nlohmann_json
        PREFIX ${CMAKE_CURRENT_BINARY_DIR}/deps
        GIT_REPOSITORY https://github.com/nlohmann/json.git
        BUILD_COMMAND ""
        TEST_COMMAND ""
        INSTALL_COMMAND ""
    )
    target_include_directories(discordcpp PUBLIC ${CMAKE_CURRENT_BINARY_DIR}/deps/src/nlohmann_json/single_include)
else()
    target_include_directories(discordcpp PUBLIC ${nlohmann_json_INCLUDE_DIRS})
endif()


add_subdirectory(example)

add_subdirectory(test)
