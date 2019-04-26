#include "circular_linked_list.cc"

#include <iostream>

using namespace std;

int main() {
  CircularLinkedList<int> list;
  cout << list.to_string() << endl;

  list.insert(5);
  cout << list.to_string() << endl;

  list.insert(2);
  cout << list.to_string() << endl;

  list.insert(4);
  cout << list.to_string() << endl;

  list.insert(3);
  cout << list.to_string() << endl;


  list.erase(0);
  cout << list.to_string() << endl;

  cout << list.find(5) << endl;
}
