#pragma once
#include <functional>
#include <boost/type_index.hpp>
#include <vector>

void function(int)
{

}

void auto_test()
{
    std::function<void(int)> f = &function;
    auto f_auto = &function;

    std::cout << "size of function using std::function "<< sizeof(f) << std::endl;
    std::cout << "size of function using auto " << sizeof(f_auto) << std::endl;
    std::cout << "type of std::function " << boost::typeindex::type_id_with_cvr<decltype(f)>().pretty_name() << std::endl;
    std::cout << "type of auto " << boost::typeindex::type_id_with_cvr<decltype(f_auto)>().pretty_name() << std::endl;
    
    std::vector<bool> l;
    l.push_back(true);
    auto item = static_cast<bool>(l[0]);
    std::cout << "first item of vector<bool>: " << item << std::endl;
    std::cout << "type of vector<bool> " << boost::typeindex::type_id_with_cvr<decltype(l[0])>().pretty_name() << std::endl;

    int a = 8;
    int& b = a;
    int const * const c = &b;
    const int d = 56;

    auto aa = a;
    auto ab = b;
    auto ac = c;
    auto ad = d;

    //All should be deducted removing const ref qualifiers
    std::cout << "int: " << boost::typeindex::type_id_with_cvr<decltype(aa)>().pretty_name() << std::endl;
    std::cout << "int&: " << boost::typeindex::type_id_with_cvr<decltype(ab)>().pretty_name() << std::endl;
    std::cout << "int const * const: " << boost::typeindex::type_id_with_cvr<decltype(ac)>().pretty_name() << std::endl;
    std::cout << "const int: " << boost::typeindex::type_id_with_cvr<decltype(ad)>().pretty_name() << std::endl;

    // auto testA{1, 2, 3}; //c++11: std initializer list, c++14: ilformed
    auto testB{1}; // c++11 std initilizer list, c++14: int
    auto testC = {1, 2, 3}; // std::initializer list
    auto testD = {1}; // std::initializer list

    std::cout << "auto testB{1} (int): " << boost::typeindex::type_id_with_cvr<decltype(testB)>().pretty_name() << std::endl;
    std::cout << "auto testC = {1, 2, 3} (std::initilizer_list): " << boost::typeindex::type_id_with_cvr<decltype(testC)>().pretty_name() << std::endl;
    std::cout << "auto testD = {1}: (std::initializer_list)" << boost::typeindex::type_id_with_cvr<decltype(testD)>().pretty_name() << std::endl;

}
