#pragma once
#include <typeinfo>
#include <boost/type_index.hpp>
#include <vector>
#include <string>

template<typename T>
void f_ref(T& param)
{
    (void)param;
    std::cout << boost::typeindex::type_id_with_cvr<T>().pretty_name() << std::endl;
}

template<typename T>
void f_const_ref(const T& param)
{
    (void)param;
    std::cout << boost::typeindex::type_id_with_cvr<T>().pretty_name() << std::endl;
}

template<typename T>
void f_universal_ref(T&& param)
{
    (void)param;
    std::cout << boost::typeindex::type_id_with_cvr<T>().pretty_name() << std::endl;
}

template<typename T>
void f_value(T param)
{
    (void)param;
    std::cout << boost::typeindex::type_id_with_cvr<T>().pretty_name() << std::endl;
}

template<typename Container, typename Index>
decltype(auto) authAndAccess(Container&& c, Index i)
{
    std::cout << "container type:" << boost::typeindex::type_id_with_cvr<decltype(c)>().pretty_name() << std::endl;
    std::cout << "return type:" << boost::typeindex::type_id_with_cvr<decltype(c[i])>().pretty_name() << std::endl;
    c.push_back(new std::string());
    return std::forward<decltype(c[i])>(c[i]);
}

template<typename T>
class TypeDisplayer;

void type_deduction()
{
    int x = 27;
    const int const_int = x;
    const int& const_reference_int = x;

    const char* const ptr_const_const = "Fun with pointers";
    char* const ptr_const = "Fun with pointers";
    const char array_const[] = "sdasdasd";
    char array[] = "sdasdasd";

    std::cout << "==================f_ref================"<< std::endl;
    f_ref(x);
    f_ref(const_int);
    f_ref(const_reference_int);
    f_ref(array);
    f_ref(array_const);

    std::cout << "==================f_const_ref================"<< std::endl;
    f_const_ref(x);
    f_const_ref(const_int);
    f_const_ref(const_reference_int);
    f_const_ref(array);
    f_const_ref(array_const);

    std::cout << "==================f_universal_ref================"<< std::endl;
    f_universal_ref(x);
    f_universal_ref(const_int);
    f_universal_ref(const_reference_int);
    f_universal_ref(array);
    f_universal_ref(array_const);

    std::cout << "==================f_value================"<< std::endl;
    f_value(x);
    f_value(const_int);
    f_value(const_reference_int);
    f_value(ptr_const_const);
    f_value(ptr_const);
    f_value(array_const);
    f_value(array);


    const int* const a = &const_int;
    std::cout << "decltype" << boost::typeindex::type_id_with_cvr<const int * const>().pretty_name() << ":"
              << boost::typeindex::type_id_with_cvr<decltype(a)>().pretty_name() << std::endl;


    std::vector<std::string*> container;
    std::string str = "dsa";

    container.push_back(&str);
    container.at(0)->at(0);

    decltype(auto) returnResult = authAndAccess(container, 0);
    //TypeDisplayer<decltype(returnResult)> cl;

    std::cout << "return type:" << boost::typeindex::type_id_with_cvr<decltype(container[0])>().pretty_name() << std::endl;
    std::cout << "return type:" << boost::typeindex::type_id_with_cvr<decltype(returnResult)>().pretty_name() << std::endl;

}
