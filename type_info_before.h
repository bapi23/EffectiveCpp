#pragma once
#include <map>
#include <typeinfo>
#include <utility>
#include <cassert>
#include <typeindex>



void type_info_before()
{

    assert(typeid(char).hash_code() == typeid(char).hash_code());
    assert(typeid(double const * const).hash_code() == typeid(double const *).hash_code());
    std::cout << typeid(double const * const).name();

    std::map<std::type_index, std::string> map;

    map.insert(std::make_pair(std::type_index(typeid(char)), "char"));
    map.insert(std::make_pair(std::type_index(typeid(int)), "int"));
    map.insert(std::make_pair(std::type_index(typeid(double)), typeid(double).name()));
    map.insert(std::make_pair(std::type_index(typeid(float)), typeid(float).name()));
    map.insert(std::make_pair(std::type_index(typeid(bool)), typeid(bool).name()));

    for(auto& a: map)
    {
        std::cout << a.second << std::endl;
    }
}


