#include "vector.h"

#include <stdexcept>

template <typename T>
const std::string Vector<T>::kOutOfRangeMsg_ = "Vector out of range.";


template <typename T>
Vector<T>::Vector(int init_capacity)
    : data_(new int[init_capacity]),  size_(), capacity_(init_capacity) {}

template <typename T>
Vector<T>::~Vector() {
  delete[] data_;
}


template <typename T>
void Vector<T>::push_back(T val) {
  insert(size_, val);
}

template <typename T>
void Vector<T>::push_front(T val) {
  insert(0, val);
}

template <typename T>
void Vector<T>::pop_back() {
  erase(size_ - 1);
}

template <typename T>
void Vector<T>::pop_front() {
  erase(0);
}


template <typename T>
void Vector<T>::insert(int index, T val) {
  if (size_ == capacity_) {
    resize(capacity_ * 2);
  }

  // 0 1 2 3 4 5
  // 1 2 4 5 6
  //     ^
  // 1 2 3 4 5 6
  for (int i = size_; i > index; i--) {
    data_[i] = data_[i - 1];
  }
  data_[index] = val;
  size_++;
}

template <typename T>
void Vector<T>::erase(int index) {
  if (index >= (int) size_) {
    throw std::out_of_range(kOutOfRangeMsg_);
  }

  // 0 1 2 3 4
  // 1 2 4 5 6
  //     ^
  // 1 2 5 6
  for (int i = index; i < (int) size_ - 1; i++) {
    data_[i] = data_[i + 1];
  }
  size_--;

  if (size_ <= capacity_ / 4) {
    resize(capacity_ / 2);
  }
}

template <typename T>
void Vector<T>::remove(T val) {
  for (int i = 0; i < size_; i++) {
    if (data_[i] == val) {
      erase(i);
      return;
    }
  }
}

template <typename T>
int Vector<T>::find(T val) {
  // Linear search
  for (int i = 0; i < size_; i++) {
    if (data_[i] == val) {
      return i;
    }
  }
  return -1;
}

template <typename T>
void Vector<T>::clear() {
  size_ = 0;
  capacity_ = DEFAULT_SIZE;
}


template <typename T>
size_t Vector<T>::size() const {
  return size_;
}

template <typename T>
size_t Vector<T>::capacity() const {
  return capacity_;
}

template <typename T>
bool Vector<T>::empty() const {
  return size_ == 0;
}

template <typename T>
T Vector<T>::at(int index) const {
  if (index >= (int) size_) {
    throw std::out_of_range(kOutOfRangeMsg_);
  }
  return data_[index];
}

template <typename T>
T Vector<T>::front() const {
  return at(0);
}

template <typename T>
T Vector<T>::back() const {
  return at(size_ - 1);
}


template <typename T>
std::string Vector<T>::to_string() const {
  std::string s;
  for (int i = 0; i < (int) size_; i++) {
    s += std::to_string(data_[i]);
    s += (i != (int) size_ - 1) ? "->" : "";
  }
  return s;
}


template <typename T>
void Vector<T>::resize(size_t new_size) {
  new_size = (new_size <= DEFAULT_SIZE) ? DEFAULT_SIZE : new_size;
  T* new_data = new T[new_size];

  int i = 0;
  for (; i < (int) size_; i++) {
    new_data[i] = data_[i];
  }
  for (; i < (int) new_size; i++) {
    new_data[i] = 0;
  }

  delete data_;
  data_ = new_data;
}
