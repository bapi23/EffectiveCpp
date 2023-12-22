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


}
