#include <iostream>

class A {
public:
  A() : a_() {} // you can init nullptr like this
  A* a_;
};

int main() {
  A a;
  std::cout << (a.a_ == nullptr) << std::endl;
}
