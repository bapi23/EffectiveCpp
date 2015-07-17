#pragma once
#include <type_traits>

class Test
{
    friend class Friend;
public:
    Test() = delete;
    Test(const Test& t) = delete;
    Test& operator = (const Test& t) = delete;
};

class Test_old
{
    friend class Friend;
public:
    Test_old(){};
    Test_old(const Test& t){ (void)t;}
    Test_old& operator = (const Test_old& t){ (void)t; return *this; }
};

class Test_2
{
public:
    void fun(int a){ (void)a; std::cout <<"int version";  }
    void fun(char a) = delete;
    void fun(bool a) = delete;
    void fun(double d) = delete;
};

class Friend
{
public:
    Friend()
    {
        //Test t;
        Test_old t;
    }
};

class ParametrizedDelete
{
public:

    template<typename T>
    void function(T a)
    {}
};

template<>
void ParametrizedDelete::function<bool>(bool a) = delete;

template<typename T>
void fun_44()
{
}

template<>
void fun_44<bool>() = delete;


void delete_()
{
    Test_2 t;
    (void)t;
//    t.fun(4.5);
//    t.fun(true);
//    t.fun('e');

    ParametrizedDelete p2;
    p2.function("s");
//    p2.function(true);

    fun_44<int>();
    //fun_44<bool>();
}
