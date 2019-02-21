#include "stack.cpp"
#include <iostream>

using std::cout;
using std::endl;

int main() {
    Stack<int> stack;
    stack.push(8);
    stack.push(7);
    stack.push(6);
    stack.push(0);
    stack.push(3);
    cout << stack.ToString() << endl;
}
