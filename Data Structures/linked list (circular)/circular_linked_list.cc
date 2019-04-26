#include "circular_linked_list.h"

#include <stdexcept>

template <typename T>
const std::string CircularLinkedList<T>::kOutOfRangeMsg_ = "Circular Linked List out of range.";


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
    while (ptr->next->val < val && ptr->next != head_) {
      ptr = ptr->next;
    }
    new_node->next = ptr->next;
    ptr->next = new_node;

    if (val < head_->val) {
      head_ = new_node;
    }
  }
  size_++;
}

template <typename T>
void CircularLinkedList<T>::erase(int index) {
  if (index >= (int) size_) {
    throw std::out_of_range(kOutOfRangeMsg_);
  }

  if (head_->next == head_) {
    delete head_;
    head_ = nullptr;
  } else {
    index = (index == 0) ? size_ : index;

    Node* ptr = head_;
    for (int i = 0; i < index - 1; i++) {
      ptr = ptr->next;
    }
    Node* trash = ptr->next;
    ptr->next = trash->next;
    delete trash;

    if (index == (int) size_) {
      head_ = ptr->next;
    }
  }
  size_--;
}

template <typename T>
int CircularLinkedList<T>::find(T val) const {
  int i = 0;
  Node* ptr = head_;
  for (; ptr && ptr->next != head_; i++) {
    if (ptr->val == val) {
      return i;
    }
    ptr = ptr->next;
  }
  return (ptr->val == val) ? i : -1;
}


template <typename T>
size_t CircularLinkedList<T>::size() const {
  return size_;
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
