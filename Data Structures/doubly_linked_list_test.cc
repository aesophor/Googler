#include "doubly_linked_list.cc"

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
  list.pop_front();
  list.pop_front();

  cout << list.to_string() << endl;
}
