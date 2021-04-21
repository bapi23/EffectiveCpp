cmake_minimum_required(VERSION 3.10)
project(EffectiveCpp)

add_subdirectory(c++14)

add_executable(effectivecpp main.cpp pimpl.cpp)
target_link_libraries(effectivecpp pthread)
