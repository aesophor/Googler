#include "queue.h"

#include <stdexcept>

template <typename T>
const std::string Queue<T>::kOutOfRangeMsg_ = "Queue out of range.";


template <typename T>
Queue<T>::Node::Node(T val) : val(val), next() {}

template <typename T>
Queue<T>::Queue() : head_(), tail_(), size_() {}

template <typename T>
Queue<T>::~Queue() {
  clear();
}


template <typename T>
void Queue<T>::push(T val) {
  Node* new_node = new Node(val);

  if (size_ == 0) {
    head_ = new_node;
  } else {
    tail_->next = new_node;
  }
  tail_ = new_node;
  size_++;
}

template <typename T>
void Queue<T>::pop() {
  if (size_ == 0) {
    throw std::out_of_range(kOutOfRangeMsg_);
  }

  Node* old_head = head_;
  head_ = head_->next;
  delete old_head;
  size_--;

  if (!head_) {
    tail_ = nullptr;
  }
}

template <typename T>
void Queue<T>::clear() {
  Node* ptr = head_;
  while (ptr) {
    Node* next = ptr->next;
    delete ptr;
    ptr = next;
  }
  size_ = 0;
}


template <typename T>
size_t Queue<T>::size() const {
  return size_;
}

template <typename T>
bool Queue<T>::empty() const {
  return size_ == 0;
}

template <typename T>
T Queue<T>::front() const {
  if (size_ == 0) {
    throw std::out_of_range(kOutOfRangeMsg_);
  }
  return head_->val;
}

template <typename T>
std::string Queue<T>::to_string() const {
  std::string s;
  Node* ptr = head_;
  while (ptr) {
    s += std::to_string(ptr->val);
    s += (ptr->next) ? "->" : "";
    ptr = ptr->next;
  }
  return s;
}
