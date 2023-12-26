#include <iostream>

namespace fold_expressions{
template <typename ...Args>
auto sum(Args&&... args){
    return (args + ...);
}

template <typename ...T, typename Func>
auto map(Func fun, T... args){
    return (args * ...);
}

template <typename T1, typename T2>
auto mult(T1 t1, T2 t2){
    return t1 * t2;
}

void main_(){
    std::cout << "Sum: " << sum(false, 1, 1, 4.5, 3, 6.7, true) << std::endl;
}

}