#include "circular_linked_list.h"

template <typename T>
CircularLinkedList<T>::Node::Node(T val) : val(val), next() {}

template <typename T>
CircularLinkedList<T>::CircularLinkedList() : head_(), size_() {}

template <typename T>
CircularLinkedList<T>::~CircularLinkedList() {
  Node* ptr = head_;
  while (ptr && ptr->next != head_) {
    Node* next = ptr->next;
    delete ptr;
    ptr = next;
  }
}


template <typename T>
void CircularLinkedList<T>::insert(T val) {
  Node* new_node = new Node(val);

  if (!head_) {
    head_ = new_node;
    head_->next = head_;
  } else {
    // *2 -> 5 -> *2
    // *2 -> 3 -> 5 -> *2
    Node* ptr = head_;
    while (ptr && ptr->next != head_ && ptr->next->val < val) {
      ptr = ptr->next;
    }
    new_node->next = ptr->next;
    ptr->next = new_node;

    if (val < head_->val) {
      head_ = new_node;
    }
  }
}


template <typename T>
std::string CircularLinkedList<T>::to_string() const {
  std::string s;
  Node* ptr = head_;
  while (ptr) {
    s += std::to_string(ptr->val);
    s += (ptr->next != head_) ? "->" : "";
    if (ptr->next != head_) {
      ptr = ptr->next;
    } else {
      break;
    }
  }
  return s;
}
