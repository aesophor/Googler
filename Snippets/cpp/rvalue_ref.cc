#include <iostream>

class A {
public:
  A() = default;
  virtual ~A() = default;
};

int main() {
  //A& a = A();     // non-const lvalue ref to 'A' cannot bind to temporary 'A'
  const A& a = A(); // ok
  A&& aa = A();     // rvalue ref. hehe boi
}
