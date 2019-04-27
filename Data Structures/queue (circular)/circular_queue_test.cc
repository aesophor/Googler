#include "circular_queue.cc"

#include <iostream>

using namespace std;

int main() {
  CircularQueue<int> q;

  q.push(3);
  cout << q.to_string() << endl;

  q.push(5);
  cout << q.to_string() << endl;
  
  q.push(4);
  cout << q.to_string() << endl;

  q.push(2);
  cout << q.to_string() << endl;

  q.push(1);
  cout << q.to_string() << endl;

  // full
  
  // start overwriting head
  q.push(6);
  cout << q.to_string() << endl;


  q.pop();
  cout << q.to_string() << endl;

  q.pop();
  cout << q.to_string() << endl;

  q.push(6);
  cout << q.to_string() << endl;
}
