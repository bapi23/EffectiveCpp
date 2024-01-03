#include "designated.hpp"
#include "jthread.hpp"
#include "coroutines.hpp"
#include "ranges.hpp"
#include "concepts.hpp"

int main(){
    std::cout << "designated test" << std::endl;
    designated_test();
    jthread_test();
    coroutines_test();
    coroutines_test2();
    ranges_test();
    concepts_test();
}