#include "doubly_linked_list.cc"

#include <iostream>

using namespace std;

int main() {
  DoublyLinkedList<int> list;
  list.push_back(3);
  list.push_back(4);
  list.push_back(5);
  list.pop_back();
  list.pop_back();
  list.pop_back();
  
  list.push_back(5);
  list.push_front(3);
  list.insert(2, 2);
  cout << list.to_string() << endl;

  cout << list.at(0) << endl;
  cout << list.at(1) << endl;

  list.erase(2);

  cout << list.to_string() << endl;
}
