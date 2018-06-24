cmake_minimum_required(VERSION 2.8)

add_executable(
    cli
    cli.cpp
)

target_link_libraries(cli discordcpp)