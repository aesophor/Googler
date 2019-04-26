#ifndef CIRCULAR_LINKED_LIST_H_
#define CIRCULAR_LINKED_LIST_H_

#include <string>

// This data structure will always maintain its elements
// as a sorted linked list.
// e.g., *2 -> 3 -> 5 -> *2 , where *2 means they are the very same node
// 
// If 6 is inserted, then *2 -> 3 -> 5 -> 6 -> *2 is how the list looks
// after insertion.
template <typename T>
class CircularLinkedList {
 public:
  CircularLinkedList();
  virtual ~CircularLinkedList();

  void insert(T val);
  void erase(int index);
  int find(T val) const;

  size_t size() const;
  std::string to_string() const;

 private:
  struct Node {
    Node(T val);
    T val;
    Node* next;
  };

  static const std::string kOutOfRangeMsg_;
  Node* head_; // always points to the min element
  size_t size_;
};

#endif // CIRCULAR_LINKED_LIST_H_
