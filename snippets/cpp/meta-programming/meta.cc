#include <iostream> 

template<int base, int exp>
struct power {
  static constexpr int val = base * power<base, exp-1>::val;
};

template<>
struct power<2, 0> { 
  static constexpr int val = 1;
}; 


int main(int argc, char* args[]) { 
  std::cout << power<2, 8>::val << std::endl;  // 256 (evaluated at compile time)
} 

