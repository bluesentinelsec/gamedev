cmake_minimum_required(VERSION 3.10)

project(Pong VERSION 1.0)

add_executable(Pong src/main.cpp)

find_package(SFML COMPONENTS system window graphics CONFIG REQUIRED)
target_link_libraries(Pong PRIVATE sfml-system sfml-network sfml-graphics sfml-window)

