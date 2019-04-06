#include "circular_buffer.cc"
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
  c.enqueue(6);
  c.enqueue(7);
  c.dequeue();

  cout << c.ToString() << endl;
}
