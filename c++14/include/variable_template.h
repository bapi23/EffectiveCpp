#include <iostream>

namespace variable_template {

template<class T>
constexpr T pi = T(3.1415926535897932385L);  // variable template
 
template<class T>
T circular_area(T r) // function template
{
    return pi<T> * r * r; // pi<T> is a variable template instantiation
}

void main_()
{
    std::cout << "area: " << circular_area(5) << std::endl;
    std::cout << "area: " << circular_area<float>(5) << std::endl;
    std::cout << "pi<float>: " << pi<float> << std::endl;
    std::cout << "pi<int>: " << pi<int> << std::endl;
}

}