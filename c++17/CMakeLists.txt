cmake_minimum_required(VERSION 3.10)

add_executable(effectivecpp17 src/main.cpp)
target_include_directories(effectivecpp17 PRIVATE include)

target_compile_features(effectivecpp17 PRIVATE cxx_std_17)
