#include <algorithm>
#include <vector>
#include <string>
#include <typeinfo>

#include <boost/type_index.hpp>

// Perfect forward decltype deduces differently then template deduction

namespace decltype_auto{

template<class Fun, class... Args>
decltype(auto) call_and_return(Fun fun, Args&&... args) 
{ 
    return fun(std::forward<Args>(args)...); 
}

int* example(int *a){
    return a;
}

void main_(){
    int x = 5;
    decltype(auto) a = (x);

    std::cout << "decltype of decltype(auto) a = (x):  " << boost::typeindex::type_id_with_cvr<decltype(a)>().pretty_name() << std::endl;

    int z;
    auto c = call_and_return(&example, &z);
    std::cout << "decltype of return type" << boost::typeindex::type_id_with_cvr<decltype(c)>().pretty_name() << std::endl;
}

} // decltype_auto