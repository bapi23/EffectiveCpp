cmake_minimum_required(VERSION 3.10)

add_executable(effectivecpp src/main.cpp src/pimpl.cpp)
target_link_libraries(effectivecpp pthread)
target_include_directories(effectivecpp PRIVATE include)
