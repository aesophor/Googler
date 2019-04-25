#include "stack.cc"

#include <iostream>

using namespace std;

int main() {
  Stack<int> s;

  s.push(3);
  cout << s.to_string() << endl;

  s.push(5);
  cout << s.to_string() << endl;

  s.pop();
  cout << s.to_string() << endl;

  s.pop();
  cout << s.to_string() << endl;
}
