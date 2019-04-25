#include "doubly_linked_list.h"

#include <stdexcept>

template <typename T>
const std::string DoublyLinkedList<T>::kOutOfRangeMsg_ = "Doubly Linked List out of range";


template <typename T>
DoublyLinkedList<T>::Node::Node(T val) : val(val), prev(), next() {}

template <typename T>
DoublyLinkedList<T>::DoublyLinkedList() : head_(), tail_(), size_() {}

template <typename T>
DoublyLinkedList<T>::~DoublyLinkedList() {
  clear();
}


template <typename T>
void DoublyLinkedList<T>::push_back(T val) {
  Node* new_node = new Node(val);

  if (size_ == 0) {
    head_ = new_node;
  } else {
    new_node->prev = tail_;
    tail_->next = new_node;
  }
  tail_ = new_node;
  size_++;
}

template <typename T>
void DoublyLinkedList<T>::push_front(T val) {
  Node* new_node = new Node(val);

  if (size_ == 0) {
    tail_ = new_node;
  } else {
    head_->prev = new_node;
    new_node->next = head_;
  }
  head_ = new_node;
  size_++;
}

template <typename T>
void DoublyLinkedList<T>::pop_back() {
  if (size_ == 0) {
    throw std::out_of_range(kOutOfRangeMsg_);
  }

  Node* old_tail = tail_;
  tail_ = tail_->prev;
  delete old_tail;
  size_--;

  if (tail_) {
    tail_->next = nullptr;
  } else {
    head_ = nullptr;
  }
}

template <typename T>
void DoublyLinkedList<T>::pop_front() {
  if (size_ == 0) {
    throw std::out_of_range(kOutOfRangeMsg_);
  }

  Node* old_head = head_;
  head_ = head_->next;
  delete old_head;
  size_--;

  if (head_) {
    head_->prev = nullptr;
  } else {
    tail_ = nullptr;
  }
}


template <typename T>
void DoublyLinkedList<T>::insert(size_t index, T val) {
  Node* new_node = new Node(val);

  if (index < 0 || index > size_) {
    throw std::out_of_range(kOutOfRangeMsg_);
  } else if (index == 0) {
    push_front(val);
  } else if (index == size_) {
    push_back(val);
  } else {
    Node* ptr = head_;
    for (size_t i = 0; i < index - 1; i++) {
      ptr = ptr->next;
    }
    ptr->next->prev = new_node;
    new_node->next = ptr->next;
    new_node->prev = ptr;
    ptr->next = new_node;
    size_++;
  }
}

template <typename T>
void DoublyLinkedList<T>::erase(size_t index) {
  if (index < 0 || index >= size_) {
    throw std::out_of_range(kOutOfRangeMsg_);
  } else if (index == 0) {
    pop_front();
  } else if (index == size_ - 1) {
    pop_back();
  } else {
    Node* ptr = head_;
    for (size_t i = 0; i < index; i++) {
      ptr = ptr->next;
    }
    ptr->prev->next = ptr->next;
    ptr->next->prev = ptr->prev;
    delete ptr;
    size_--;
  }
}

template <typename T>
void DoublyLinkedList<T>::remove(T val) {
  Node* ptr = head_;
  while (ptr) {
    if (ptr->val == val) {
      ptr->prev->next = ptr->next;
      ptr->next->prev = ptr->prev;
      delete ptr;
      size_--;
      return;
    }
    ptr = ptr->next;
  }
}

template <typename T>
size_t DoublyLinkedList<T>::find(T val) {
  Node* ptr = head_;
  for (size_t i = 0; i < size_; i++) {
    if (ptr->val == val) {
      return i;
    }
    ptr = ptr->next;
  }
  return -1;
}

template <typename T>
void DoublyLinkedList<T>::clear() {
  Node* ptr = head_;
  while (ptr) {
    Node* next = ptr->next;
    delete ptr;
    ptr = next;
  }
  size_ = 0;
}


template <typename T>
size_t DoublyLinkedList<T>::size() const {
  return size_;
}

template <typename T>
bool DoublyLinkedList<T>::empty() const {
  return size_ == 0;
}

template <typename T>
T DoublyLinkedList<T>::front() const {
  return head_->val;
}

template <typename T>
T DoublyLinkedList<T>::back() const {
  return tail_->val;
}

template <typename T>
T DoublyLinkedList<T>::at(size_t index) const {
  Node* ptr = head_;
  for (size_t i = 0; i < index && ptr; i++) {
    ptr = ptr->next;
  }

  if (!ptr) {
    throw std::out_of_range("Doubly Linked List out of range.");
  }
  return ptr->val;
}


template <typename T>
std::string DoublyLinkedList<T>::to_string() const {
  std::string s;
  Node* ptr = head_;
  while (ptr) {
    s += std::to_string(ptr->val);
    s += (ptr->next) ? "->" : "";
    ptr = ptr->next;
  }
  return s;
}
