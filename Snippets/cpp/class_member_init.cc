#include <iostream>

class A {
public:
  A() : a_() {}
  A* a_;
};

int main() {
  A a;
  std::cout << (a.a_ == nullptr) << std::endl;
}
