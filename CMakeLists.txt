cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_FLAGS "-no-pie")
set(CMAKE_C_COMPILER "gcc-13")
set(CMAKE_CXX_COMPILER "g++-13")
set(CMAKE_CXX_FLAGS "-Wl,-ld_classic")

project(EffectiveCpp)

add_subdirectory(c++11)
add_subdirectory(c++14)
add_subdirectory(c++17)
add_subdirectory(c++20)
add_subdirectory(c++23)
