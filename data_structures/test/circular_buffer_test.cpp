#include "circular_buffer.cpp"
#include <iostream>
#include <string>

using namespace std;

int main() {
    CircularBuffer<int> c = CircularBuffer<int>(5);
    c.enqueue(1);
    c.enqueue(2);
    c.enqueue(3);
    c.enqueue(4);
    c.enqueue(5);
    
    cout << c.ToString() << endl;

    c.enqueue(6);
    cout << c.ToString() << endl;
}
