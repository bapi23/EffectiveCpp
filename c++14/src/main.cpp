#include <iostream>
#include "literals.h"
#include "decltype_auto.h"
#include "generalized_lambda_capture.h"
#include "variable_template.h"
#include "std_lib.h"


int main(){
    std::cout << "===== decltype(auto) ====" << std::endl;
    decltype_auto::main_();
    std::cout << "===== literals ====" << std::endl;
    literals::main_();
    std::cout << "==== generalized lambda capture ====" << std::endl;
    generalized_lambda_captures::main_();
    std::cout << "==== variable template ====" << std::endl;
    variable_template::main_();
    std::cout << "==== std_lib ====" << std::endl;
    std_lib::main_();
}