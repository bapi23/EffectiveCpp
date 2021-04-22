#pragma once
#include <type_traits>
#include <boost/type_index.hpp>

void type_traits()
{
    std::remove_reference<int&&>::type s1; //c++11
    std::remove_reference_t<const int&> s2 = s1; //c++14
    std::remove_const_t<const int> s3 = s1; //c++14

    std::cout << "return type:" << boost::typeindex::type_id_with_cvr<decltype(s1)>().pretty_name() << std::endl;
    std::cout << "return type:" << boost::typeindex::type_id_with_cvr<decltype(s2)>().pretty_name() << std::endl;
    std::cout << "return type:" << boost::typeindex::type_id_with_cvr<decltype(s3)>().pretty_name() << std::endl;
}
