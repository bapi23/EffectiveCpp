#pragma once
#include <array>

constexpr auto size = 34;
int a = 2;


std::array<int, size> b;

constexpr
int pow(int base, int exp) noexcept
{
    return(exp == 0? 1: base*pow(base, exp-1));
}

constexpr
int powcpp14(int base, int exp) noexcept
{
    int result = 1;
    for(int i = 0; i < exp; ++i)
    {
        result*=base;
    }
    return result;
}

void constexpr_()
{
    constexpr auto numConds = 4;
    std::array<int, pow(3, numConds)> results;
    (void)results;

    std::array<int, powcpp14(3, numConds)> results2;
    (void)results2;
}
