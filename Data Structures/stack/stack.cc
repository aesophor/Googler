#include "stack.h"

#include <stdexcept>

template <typename T>
const std::string Stack<T>::kOutOfRangeMsg_ = "Stack out of range.";


template <typename T>
Stack<T>::Node::Node(T val) : val(val), next() {}

template <typename T>
Stack<T>::Stack() : top_(), size_() {}

template <typename T>
Stack<T>::~Stack() {
  clear();
}


template <typename T>
void Stack<T>::push(T val) {
  Node* new_node = new Node(val);

  if (size_ == 0) {
    top_ = new_node;
  } else {
    new_node->next = top_;
    top_ = new_node;
  }
  size_++;
}

template <typename T>
void Stack<T>::pop() {
  if (size_ == 0) {
    throw std::out_of_range(kOutOfRangeMsg_);
  }
  
  Node* old_top = top_;
  top_ = top_->next;
  delete old_top;
  size_--;
}

template <typename T>
void Stack<T>::clear() {
  Node* ptr = top_;
  while (ptr) {
    Node* next = ptr->next;
    delete ptr;
    ptr = next;
  }
  size_ = 0;
}


template <typename T>
size_t Stack<T>::size() const {
  return size_;
}

template <typename T>
bool Stack<T>::empty() const {
  return size_ == 0;
}

template <typename T>
T Stack<T>::top() const {
  if (size_ == 0) {
    throw std::out_of_range(kOutOfRangeMsg_);
  }
  return top_->val;
}

template <typename T>
std::string Stack<T>::to_string() const {
  std::string s;
  Node* ptr = top_;
  while (ptr) {
    s += std::to_string(ptr->val);
    s += (ptr->next) ? "->" : "";
    ptr = ptr->next;
  }
  return s;
}
