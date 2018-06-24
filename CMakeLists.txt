cmake_minimum_required(VERSION 2.8)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake)

find_package(Boost COMPONENTS system REQUIRED)
find_package(nlohmann_json REQUIRED)
find_package(Openssl REQUIRED)

add_library(
    discordcpp
    src/client.cpp
    src/gateway.cpp
    src/rest_api.hpp
    src/rest_api.cpp
)

target_link_libraries(discordcpp ${Boost_SYSTEM_LIBRARIES} ${OPENSSL_LIBRARIES})

target_include_directories(
    discordcpp PUBLIC include
    ${Boost_INCLUDE_DIRS}
    ${nlohmann_json_INCLUDE_DIRS}
)

add_subdirectory(example)