#include <cassert>
#include <memory>
#include <iostream>
namespace generalized_lambda_captures{



void main_(){
    std::unique_ptr<int> ptr(new int(10));
    auto lambda = [value = std::move(ptr)] {return *value;};
    assert(ptr == nullptr);

    int x = 4;
    auto y = [&r = x, x = x+1]()->int { 
        r += 2;
        return x+2;
    }();
    std::cout << "x = 4 captured by reference: " << x << std::endl;

    int a = 67;
    auto xLam = [&] -> int{
        a = a+45;
        return a;
    };
    std::cout << "a: " << xLam() << std::endl;
}

}