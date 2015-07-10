#pragma once
#include <utility>
#include <memory>
#include <vector>
#include <map>
#include <tuple>

typedef void(*FunctionPointer)(int);
using FP = void (*)(int);

template<typename T>
using Ptr = std::shared_ptr<std::pair<int, T>>;

template<typename DEADBEEF, typename Zorro>
using Dead = std::vector<std::map<int, std::shared_ptr<std::tuple<int, DEADBEEF, Zorro>>>>;

template<typename Gz>
using G = std::pair<Gz,Gz>;

template<typename T>
struct Ptr_old
{
    typedef std::shared_ptr<std::pair<int, T>> Type;
};


template<typename T>
struct Dependent_old
{
    typename Ptr_old<T>::Type k;
};

template<>
struct Dependent_old<bool>
{
    int k;
};

template<typename T>
struct Dependent
{
    Ptr<T> a;
};

void alias_declaration()
{
    FP p;
    FunctionPointer fp2;

    Ptr<int> a;
    Ptr_old<int>::Type a2;
    Ptr_old<bool>::Type k;

    Dependent_old<int> a3;
    Dependent<int> a4;

    Dead<int,int> d;

    //Dependent_old<bool>::k g;
}
