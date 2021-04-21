#include <iostream>
#include "literals.h"
#include "decltype_auto.h"
#include "generalized_lambda_capture.h"


int main(){
    std::cout << "===== decltype(auto) ====" << std::endl;
    decltype_auto::main_();
    std::cout << "===== literals ====" << std::endl;
    literals::main_();
    std::cout << "==== generalized lambda capture ====" << std::endl;
    generalized_lambda_captures::main_();
}