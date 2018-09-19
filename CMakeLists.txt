cmake_minimum_required(VERSION 3.2)
include(cmake/HunterGate.cmake)
HunterGate(
    URL "https://github.com/ruslo/hunter/archive/v0.23.27.tar.gz"
    SHA1 "70d75a25f895df3da00d8382417e8c2a08c93173"
)
project(discordcpp)
set(CMAKE_CXX_STANDARD 14)


hunter_add_package(Boost COMPONENTS system)
hunter_add_package(nlohmann_json)
hunter_add_package(OpenSSL)
find_package(Boost CONFIG COMPONENTS system REQUIRED)
find_package(nlohmann_json REQUIRED)
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
    src/asio_impl.cpp
)

target_compile_definitions(discordcpp PUBLIC "BOOST_ASIO_SEPARATE_COMPILATION" "BOOST_ERROR_CODE_HEADER_ONLY")

target_link_libraries(
    discordcpp
    Boost::boost
    Boost::system
	${OPENSSL_LIBRARIES}
	${CMAKE_THREAD_LIBS_INIT}
)

target_include_directories(
    discordcpp PUBLIC include
    ${Boost_INCLUDE_DIRS}
)

add_subdirectory(example)

add_subdirectory(test)
