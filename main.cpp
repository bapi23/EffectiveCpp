#include <iostream>
#include <typeinfo>
#include "type_info_before.h"
#include "type_deduction.h"
#include "auto.h"
#include "brace_initialazers.h"
#include "null_ptr.h"
#include "alias_declaration.h"
#include "type_traits.h"
#include "enums.h"

using namespace std;

int main()
{
    std::cout << "------------- type_info --------------" << std::endl;
    type_info_before();
    std::cout << "------------- type_deduction ---------" << std::endl;
    type_deduction();
    std::cout << "------------- auto ---------" << std::endl;
    auto_test();
    std::cout << "------------- brace_initialazers ---------" << std::endl;
    brace_initializers();
    std::cout << "------------- null_ptr ---------" << std::endl;
    null_ptr();
    std::cout << "------------- type_traits ---------" << std::endl;
    type_traits();
    std::cout << "------------- enums ---------" << std::endl;
    type_traits();
    enums();
}

