cmake_minimum_required(VERSION 2.8)

find_package(Boost COMPONENTS system REQUIRED)

add_library(
    discordcpp
    src/client.cpp
    src/gateway.hpp
    src/gateway.cpp
    src/rest_api.hpp
    src/rest_api.cpp
)

target_link_libraries(discordcpp ${Boost_LIBRARIES})

target_include_directories(discordcpp PRIVATE include)

target_include_directories(discordcpp INTERFACE ${Boost_INCLUDE_DIRS})