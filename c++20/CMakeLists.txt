cmake_minimum_required(VERSION 3.10)

add_executable(effectivecpp23 src/main.cpp)
target_include_directories(effectivecpp23 PRIVATE include)

target_compile_features(effectivecpp23 PRIVATE cxx_std_20)
