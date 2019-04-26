#ifndef DOUBLY_LINKED_LIST_H_
#define DOUBLY_LINKED_LIST_H_

#include <string>

template <typename T>
class DoublyLinkedList {
 public:
  DoublyLinkedList();
  virtual ~DoublyLinkedList();

  void push_back(T val);
  void push_front(T val);
  void pop_back();
  void pop_front();

  void insert(int index, T val);
  void erase(int index);
  void remove(T val);
  int find(T val);
  void clear();

  size_t size() const;
  bool empty() const;
  T front() const;
  T back() const;
  T at(int index) const;
  std::string to_string() const;

 private:
  struct Node {
    Node(T val);
    T val;
    Node* prev;
    Node* next;
  };

  static const std::string kOutOfRangeMsg_;
  Node* head_;
  Node* tail_;
  size_t size_;
};

#endif // DOUBLY_LINKED_LIST_H_
