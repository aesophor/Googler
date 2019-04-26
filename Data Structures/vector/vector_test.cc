#include "vector.cc"

#include <iostream>

using namespace std;

int main() {
  Vector<int> vec;
  vec.push_back(5);
  vec.push_back(6);
  vec.push_back(7);
  vec.pop_front();
  vec.pop_front();
  vec.pop_front();
  vec.push_back(9);
  vec.push_front(10);

  cout << vec.to_string() << endl;
}
