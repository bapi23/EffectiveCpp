cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_FLAGS "-no-pie")
set(CMAKE_C_COMPILER "gcc-13")
set(CMAKE_CXX_COMPILER "g++-13")
set(CMAKE_CXX_FLAGS "-Wl,-ld_classic -O3")

project(effectivecppbasics)

add_executable(effectivecppbasics src/main.cpp)
target_include_directories(effectivecppbasics PRIVATE include)

target_compile_features(effectivecppbasics PRIVATE cxx_std_23)
