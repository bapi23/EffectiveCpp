#include "expected.hpp"
#include "constexpr_allocations.hpp"
int main(){
    std::cout << "fold expressions" << std::endl;
    expected_test();
    std::cout << "constexpr allocations" << std::endl;
    constexpr_allocations_test();
}