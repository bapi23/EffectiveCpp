#pragma once


void fun1(int i)
{
    std::cout<<"fun1"<<std::endl;
}

void fun1(void* i)
{
    std::cout << "fun2" << std::endl;
}

void null_ptr()
{
    fun1(0);
    fun1(nullptr);
}
