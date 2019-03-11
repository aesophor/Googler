#include <iostream>
#include <cstring>

using namespace std;

class A {
public:
    A(char id, char* text) : id_(id) {
        cout << "Constructor called" << endl;
        text_ = new char[strlen(text) + 1];
        strcpy(text_, text);
    }

    virtual ~A() {
        cout << "Destructor called" << endl;
        delete[] text_;
    }

    friend ostream& operator<< (ostream& os, const A& a);

private:
    char id_;
    char* text_;
};

ostream& operator<< (ostream& os, const A& a) {
    return os << "ID: " << a.id_ << " " << a.text_; 
}


/*
void DisplayTitle(A* a) {
    a->Show();
}
*/

void DisplayTitle(A a) {
    cout << a << endl;
}

int main() {
    A* a = new A('A', "Some interesting title");
    DisplayTitle(*a);
    DisplayTitle(*a);
    delete a;
}
