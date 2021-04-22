#include <utility>
#include <algorithm>
#include <string>

namespace std_lib{

struct S
{
  int n;
 
  S(S&& other) noexcept : n{std::exchange(other.n, 0)}
  {}
 
  S& operator=(S&& other) noexcept 
  {
    if(this != &other)
        n = std::exchange(other.n, 0); // move n, while leaving zero in other.n
    return *this;
  }
};


void main_(){
  auto range1 = {1,2,3,4};
  auto range2 = {1,2,3,3};
  auto it = std::mismatch(range1.begin(), range1.end(), range2.begin());
  std::cout << "first mismatch "<< *it.first << " with " << *it.second << std::endl;


  auto range_perm = {2,3,4,1};
  std::cout << "is permutation: " << std::boolalpha << std::is_permutation(
              std::begin(range1), std::end(range1), std::begin(range_perm)) << std::endl;

  auto p = std::make_pair(1, std::string("string"));
  std::cout << "get<0>, get<1> (" << std::get<0>(p) << ", " << std::get<1>(p) << ")\n";
  std::cout << "get<int> get<std::string> (" << std::get<int>(p) << ", " << std::get<std::string>(p) << ")\n";
}

}