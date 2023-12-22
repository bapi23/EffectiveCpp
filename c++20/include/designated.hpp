#include <iostream>

struct A{
    int a;
    int b;
};


void designated_test(){
    auto a = A{.a=1, .b=2};
    std::cout << a.b;
}