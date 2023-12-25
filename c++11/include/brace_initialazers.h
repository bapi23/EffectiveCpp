#pragma once
#include <initializer_list>
#include <iostream>

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


    Widget w0(); // most vexing parse
    Widget w00{}; // default constructor
    Widget w1(10,true); // int, bool constuctor
    Widget w2{10, true}; // intializer list constructor
    Widget w3(10, 5.0); // int, double ctr
    Widget w4{10, 5.05}; // initializer list constructor
    Widget w5{w2}; // copy constructor

    //Widget2 w20{10, 5.0}; error in c++14 - can't narrow int to bool (tries to use initialiser list)

    Widget w6{}; // default ctr
    Widget w7{{}}; // initializer list
    Widget w8({}); // initilizer list
}
