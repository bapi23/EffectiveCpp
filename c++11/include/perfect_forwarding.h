#pragma once

#include <inttypes.h>
#include <vector>

struct ipv4Header{
    std::uint32_t version:4,
                  IHL:4,
                  DSCP:6,
                  ECN:2,
                  totalLength:16;
};


void f(int p)
{
    (void)p;
}

void f_initialiser(std::vector<int> p)
{
    (void)p;
}

template<typename T>
int fwd(T&& p)
{
    static_assert(std::is_integral<T>::value, "not integral!!!!");
    f(std::forward<ipv4Header>(p));
}

template<typename T>
void fwd_initializer_list(T&& p)
{
    f_initialiser(std::forward<T>(p));
}

void perfect_forwarding()
{
    ipv4Header l;
    f(l.totalLength);
    //fwd(l.totalLength);

    f_initialiser({1,2,3});
    //fwd_initializer_list({1,2,3}); doesn't compile because initializer_list can't be deduced
    fwd_initializer_list(std::initializer_list<int>{1,2,3});
    auto in = {1,2,3};
    fwd_initializer_list(in);

    //fwd("ss"); static assert
}
