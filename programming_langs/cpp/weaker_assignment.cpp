#include <iostream>

using namespace std;

class A {
public:
    virtual void method() {
        cout << "calling A method" << endl;
    }
};

class B : public A { 
private:
    void method() {
        cout << "calling B method" << endl;
    }
};

int main(void) {
    B b = B();
    b.method();
    ((A) b).method();

    // According to §5.4/7 of the standard:
    // a pointer to an object of derived class type or an lvalue of derived class type may be
    // explicitly converted to a pointer or reference to an unambiguous base class type
    ((A&) b).method();                  // access base object     (O)
    ((A*) &b)->method();                // C-style upcasting      (O)
    reinterpret_cast<A*>(&b)->method(); // reinterpret_cast       (O)

    // static_cast and dynamic_cast will check if the types are compatible.
    static_cast<A*>(&b)->method();      // static_cast upcasting  (X)
    dynamic_cast<A*>(&b)->method();     // dynamic_cast upcasting (X)
    ((A) b).method();                   // object slicing         (X)
}
