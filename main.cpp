#include <iostream>
#include <typeinfo>
#include "type_info_before.h"
#include "type_deduction.h"

using namespace std;

int main()
{
    std::cout << "------------- type_info--------------" << std::endl;
    type_info_before();
    std::cout << "------------- type_deduction---------" << std::endl;
    type_deduction();
}

