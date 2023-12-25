#pragma once


#include <iostream>

class A{
public:
    A(int val){
        raw = new int(0);
        *raw = val;
    }

    A(const A& a){
        raw = new int(0);
        *raw = *a.raw;
    }

    A(A&& a){
        raw = new int(0);
        *raw = *a.raw;
        delete a.raw;
        a.raw = nullptr;
    }

    A& operator=(const A& a){
        if (&a != this){
            *raw = *a.raw;
        }
        return *this;
    }

    A& operator=(A&& a){
        if (this != &a){
            *raw = *a.raw;

            //fast resource release (might be helpful in case of more expensive resources)
            delete a.raw;
            a.raw = nullptr;
        }
        return *this;
    }

    virtual ~A(){
        if (raw != nullptr){
            delete raw;
        }
    }

    int *raw;
};

void custom_copy_test(){
    A a(1);
    A b(5);
    A c(10);

    a = b = c;

    std::cout << "a = " << *a.raw << "\n";
    std::cout << "b = " << *b.raw << "\n";
    std::cout << "c = " << *c.raw << "\n";

    *c.raw = 89;
    *b.raw = 45;
    *a.raw = 8;

    std::cout << "a = " << *a.raw << "\n";
    std::cout << "b = " << *b.raw << "\n";
    std::cout << "c = " << *c.raw << "\n";


    A z(67);

    a = std::move(z);

    std::cout << "a = " << *a.raw << "\n";
    std::cout << "b = " << *b.raw << "\n";
    std::cout << "c = " << *c.raw << "\n";

    //std::cout << "c = " << *z.raw << "\n";
}

class B: public A{
    public:
    B(int val): A(val){
    }
};

void custom_copy_with_inheritance_test(){
    B b(5);
}