#include "fold.h"
#include "class_template_detuction.h"

int main(){
    std::cout << "fold expressions" << std::endl;
    fold_expressions::main_();
    std::cout << "class template deduction" << std::endl;
    class_template_deduction::main_();
}