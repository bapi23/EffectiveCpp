cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_FLAGS "-no-pie")
set(CMAKE_C_COMPILER "gcc-13")
set(CMAKE_CXX_COMPILER "g++-13")
set(CMAKE_CXX_FLAGS "-Wl,-ld_classic")

project(c_20)

add_executable(effectivecpp23 src/main.cpp)
target_include_directories(effectivecpp23 PRIVATE include)

target_compile_features(effectivecpp23 PRIVATE cxx_std_23)
