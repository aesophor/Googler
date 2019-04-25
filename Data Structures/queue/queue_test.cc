#include "queue.cc"

#include <iostream>

using namespace std;

int main() {
  Queue<int> q;

  q.push(3);
  cout << q.to_string() << endl;

  q.push(5);
  cout << q.to_string() << endl;

  q.pop();
  cout << q.to_string() << endl;

  q.pop();
  cout << q.to_string() << endl;

  q.push(6);
  cout << q.to_string() << endl;
}
