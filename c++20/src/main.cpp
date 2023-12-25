#include "designated.hpp"
#include "jthread.hpp"
#include "coroutines.hpp"

int main(){
    std::cout << "designated test" << std::endl;
    designated_test();
    jthread_test();
    coroutines_test();
    coroutines_test2();
}