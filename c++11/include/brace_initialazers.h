#pragma once
#include <initializer_list>

class Widget
{
public:
    Widget(){std::cout << "default ctr" << std::endl; }
    Widget(int i, bool b){ (void)i; (void)b; std::cout << "ctr int i, bool i" << std::endl; }
    Widget(int i, double d){ (void)i; (void)d; std::cout << "int i, double d" << std::endl; }
    Widget(std::initializer_list<long double> il){ (void)il; std::cout << "std::initializer_list<long double> il" << std::endl; }
    operator float() const { return 0.0; }
};

class Widget2
{
public:
    Widget2(){std::cout << "default ctr" << std::endl; }
    Widget2(int i, bool b){ (void)i; (void)b; std::cout << "ctr int i, bool i" << std::endl; }
    Widget2(int i, double d){ (void)i; (void)d; std::cout << "int i, double d" << std::endl; }
    Widget2(std::initializer_list<bool> il){ (void)il; std::cout << "std::initializer_list<long double> il" << std::endl; }
    operator float() const { return 0.0; }
};

void brace_initializers()
{
    long long int b = 4;
    //int a = {b}; error: cannot be narrowed from type 'long long' to 'int' in initializer list
    int c = b;
    (void)c;
    (void)b;
    //(void)a;


    Widget w0();
    Widget w1(10,true);
    Widget w2{10, true};
    Widget w3(10, 5.0);
    Widget w4{10, 5.05};
    Widget w5{w2};

    //Widget2 w20{10, 5.0}; error in c++14

    Widget w6{};
    Widget w7{{}};
    Widget w8({});
}
