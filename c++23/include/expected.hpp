#include <iostream>
#include <expected>


enum class Err {
    ErrOne = 1,
    Errtwo
};


// function returns expected
[[nodiscard]] std::expected<float, Err> funRetErr(bool retErr){
    if (retErr){
        return std::unexpected(Err::ErrOne);
    }

    return 45.6;
}

void expected_test(){
    std::cout <<"expected error: " << int(funRetErr(true).error()) << "\n";
    std::cout <<"has value: " << funRetErr(false).has_value() << "\n";;
    std::cout <<"expected value: " << funRetErr(false).value() << "\n";;
}