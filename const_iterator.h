#pragma once
#include <boost/type_index.hpp>
#include <vector>
#include <algorithm>

namespace my
{

template<typename T>
auto cbegin(const T& container) -> decltype(std::begin(container))
{
    return std::begin(container);
}

template<typename T>
auto cend(const T& container) -> decltype(std::end(container))
{
    return std::end(container);
}

}

void const_iterator()
{
    std::vector<int> a{1,2,3,4,5};
    auto it_const_1 = std::find(a.cbegin(), a.cend(), 4);
    auto it_non_const_1 = std::find(a.begin(), a.end(), 4);
    auto it_const_2 = std::find(my::cbegin(a), my::cend(a), 4);
    auto it_const_3 = std::find(std::cbegin(a), std::cend(a), 4);

    std::cout << "type of auto " << boost::typeindex::type_id_with_cvr<decltype(it_const_1)>().pretty_name() << std::endl;
    std::cout << "type of auto " << boost::typeindex::type_id_with_cvr<decltype(it_non_const_1)>().pretty_name() << std::endl;
    std::cout << "type of auto " << boost::typeindex::type_id_with_cvr<decltype(it_const_2)>().pretty_name() << std::endl;
}
