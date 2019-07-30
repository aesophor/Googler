#include "circular_queue.h"

#include <stdexcept>

template <typename T>
CircularQueue<T>::CircularQueue(int capacity)
    : data_(new int[capacity]), head_(), tail_(), size_(capacity) {}


template <typename T>
void CircularQueue<T>::push(T val) {
  data_[tail_] = val;
  
  if (full()) {
    head_ = (head_ + 1) % size_;
  }

  tail_ = (tail_ + 1) % size_;
}

template <typename T>
void CircularQueue<T>::pop() {
  head_ = (head_ + 1) % size_;
}

template <typename T>
void CircularQueue<T>::clear() {
  tail_ = 0;
  head_ = 0;
}


template <typename T>
size_t CircularQueue<T>::size() const {
  return size_;
}

template <typename T>
bool CircularQueue<T>::empty() const {
  return tail_ == head_;
}

template <typename T>
bool CircularQueue<T>::full() const {
  return (tail_ + 1) % (int) size_ == head_;
}

template <typename T>
T CircularQueue<T>::front() const {
  return data_[head_];
}

template <typename T>
std::string CircularQueue<T>::to_string() const {
  std::string s = "     ";
  for (size_t i = 0; i < size_; i++) {
    s += std::to_string(i);
    s += (i != size_ - 1) ? " " : "";
  }
  s += "\n" "     ";
  for (size_t i = 0; i < size_; i++) {
    s += std::to_string(data_[i]);
    s += (i != size_ - 1) ? " " : "";
  }
  s += "\n";

  s += "\ntail ";
  for (size_t i = 0; i < size_; i++) {
    s += (tail_ == (int) i) ? "^ " : "  ";
  }
  s += "\nhead ";
  for (size_t i = 0; i < size_; i++) {
    s += (head_ == (int) i) ? "^ " : "  ";
  }
  return s;
}
