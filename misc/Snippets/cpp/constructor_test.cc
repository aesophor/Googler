#include <iostream>

class A {
    A();
    virtual ~A();
};

int main() {
    A a();// empty parentheses interpreted as a function declaration
}
