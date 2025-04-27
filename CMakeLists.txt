cmake_minimum_required(VERSION 3.28)
project(dijkstra-cpp)

set(CMAKE_CXX_STANDARD 20)

include_directories(inc)

add_executable(dijkstra-cpp main.cpp
        src/Dijkstra.cpp
)

target_compile_options(dijkstra-cpp PRIVATE)
