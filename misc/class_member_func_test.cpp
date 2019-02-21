#include <iostream>

using namespace std;

class Circle {
public:
    Circle(int radius=5) : radius_(radius) {}
    virtual ~Circle() = default;
    virtual void area() const {
        cout << "Calculating circle area" << endl;
    }
private:
    int radius_;
};

class Ellipse : public Circle {
public:
    Ellipse() : Circle() {}
    virtual ~Ellipse() = default;
    virtual void area() const {
        cout << "Calculating ellipse area" << endl;
    }
};


int main() {
    Circle* circle;
    Ellipse ellipse;
    circle = &ellipse;
    circle->area(); // Calculating ellipse area
    // this behavior is same with java
}
