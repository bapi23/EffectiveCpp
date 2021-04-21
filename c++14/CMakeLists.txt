cmake_minimum_required(VERSION 3.10)

add_executable(effectivecpp14 src/main.cpp)
target_include_directories(effectivecpp14 PRIVATE include)

target_compile_features(effectivecpp14 PRIVATE cxx_std_14)
