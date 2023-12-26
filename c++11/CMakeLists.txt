cmake_minimum_required(VERSION 3.10)
add_executable(effectivecpp src/main.cpp src/pimpl.cpp)

set(Boost_USE_STATIC_LIBS OFF) 
set(Boost_USE_MULTITHREADED ON)  
set(Boost_USE_STATIC_RUNTIME OFF) 
find_package(Boost 1.83.0 COMPONENTS ALL) 

if(Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIRS}) 
    target_link_libraries(effectivecpp ${Boost_LIBRARIES})
endif()

target_link_libraries(effectivecpp pthread)
target_include_directories(effectivecpp PRIVATE include)

target_compile_features(effectivecpp PRIVATE cxx_std_23)