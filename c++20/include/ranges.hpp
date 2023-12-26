#include <vector>
#include <ostream>
#include <algorithm>
#include <iterator>
#include <iostream>
#include <ranges>


class Copyable {
    public:
    Copyable(int num): num(num){

    }
    Copyable(const Copyable& c) = delete;
    // Copyable(const Copyable& c){
    //     num = c.num;
    //     std::cout << "copy ctr\n";
    // }


    Copyable(Copyable&& c){
        num = c.num;
        std::cout << "move ctr\n";
    }

    Copyable& operator=(Copyable&& c){
        num = c.num;
        return *this;
    }
    
    int num;

};

std::ostream& operator <<(std::ostream& os, const Copyable& c){
    os << c.num;
    return os;
}

void ranges_test(){
    std::vector<int> a{1,2,3,4,5,5,6,7,32,4,34,34,34};
    std::ranges::copy(a, std::ostream_iterator<int>(std::cout, " "));

    std::vector<Copyable> c;//{Copyable{1},Copyable{2},Copyable{3},Copyable{4},Copyable{5}};
    c.emplace_back(1);
    c.emplace_back(2);
    c.emplace_back(3);
    c.emplace_back(4);


    //std::ranges::partition(a, [](const Copyable& c){ return c.num % 2 == 0; });
    //std::ranges::copy(c, std::ostream_iterator<Copyable>(std::cout, " "));

    auto is_odd = [](const auto& c){ return c.num % 2 == 0; };
    for(auto& z: c | std::ranges::views::filter(is_odd) | std::views::reverse)
        std::cout << z << "\n";
    std::ranges::sort(c, std::ranges::greater{}, &Copyable::num);

    std::ranges::copy(c, std::ostream_iterator<Copyable>(std::cout, " "));
}