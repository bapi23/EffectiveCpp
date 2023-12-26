#include <numeric>

constexpr auto naiveSum(unsigned int n) {
    auto p = new int[n];
    std::iota(p, p+n, 1);
    auto tmp = std::accumulate(p, p+n, 0);
    delete[] p; // no delete causes compilation error
    return tmp;
}

void constexpr_allocations_test(){
    naiveSum(5);
    static_assert(naiveSum(10) == naiveSum(10));
}