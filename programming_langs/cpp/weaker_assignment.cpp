#include <iostream>

using namespace std;

class A {
public:
    virtual void method() {
        cout << "calling A method" << endl;
    }
};

class B : private A { 
private:
    void method() override {
        cout << "calling B method" << endl;
    }
};

int main(void) {
    B b = B();
    ((A&) b).method();
}



