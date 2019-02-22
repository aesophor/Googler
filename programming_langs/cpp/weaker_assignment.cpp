#include <iostream>

using namespace std;

class A {
public:
    virtual void method() { cout << "calling A method" << endl; }
};

class B : public A { 
private:
    void method() { cout << "calling B method" << endl; }
};

int main(void) {
    A* obj = new B();
    ((B*) obj)->method();
    obj->method(); // B::method is invoked, despite it being private
}
