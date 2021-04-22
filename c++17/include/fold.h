#include <iostream>

namespace fold_expressions{
template <typename ...Args>
auto sum(Args&&... args){
    return (args + ...);
}

void main_(){
    std::cout << "Sum: " << sum(false, 1, 1, 4.5, 3, 6.7, true) << std::endl;
}

}