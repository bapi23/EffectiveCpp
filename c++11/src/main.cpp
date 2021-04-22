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
#include "delete.h"
#include "const_iterator.h"
#include "constexpr.h"
#include "unique_ptr.h"
#include "shared_ptr.h"
#include "pimpl.h"
#include "perfect_forwarding.h"
#include "async.h"
#include "condition_variable.h"
#include "promise.h"


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
    enums();
    std::cout << "------------- delete ---------" << std::endl;
    delete_();
    std::cout << "------------- const_iterator ---------" << std::endl;
    const_iterator();
    std::cout << "------------- unique_ptr ---------" << std::endl;
    unique_ptr_();
    std::cout << "------------- shared_ptr ---------" << std::endl;
    shared_ptr_();
    std::cout << "------------- pimpl ---------" << std::endl;
    pimpl();
    std::cout << "------------- perfect forwarding ---------" << std::endl;
    perfect_forwarding();
    std::cout << "------------- async ---------" << std::endl;
    async();
    std::cout << "------------- condition variable ---------" << std::endl;
    condition_varaible();
    std::cout << "------------- promise ---------" << std::endl;
    promise_();
}

