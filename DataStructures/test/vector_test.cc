#include "vector.cc"
#include <iostream>

using std::cout;
using std::endl;

int main() {
  Vector<int> vec;
  vec.push_back(3);
  vec.push_back(0);
  vec.push_back(6);
  vec.push_back(8);
  vec.push_back(8);
  vec.pop_back();
  vec.pop_back();
  vec.pop_front();
  vec.pop_front();
  vec.pop_back();
  vec.push_back(5);
  vec.push_back(3);
  vec.push_back(5);
  vec.push_back(5);
  vec.push_front(1);
  vec.push_back(0);
  cout << vec.ToString() << endl;
}
