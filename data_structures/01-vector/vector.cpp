#include "vector.hpp"
#include <stdexcept>

template <typename T>
Vector<T>::Vector(int initial_capacity) 
    : Container<T>(),
      data_(new T[initial_capacity]),
      capacity_(initial_capacity) {}


template <typename T>
int Vector<T>::size() const {
    return this->size_;
}

template <typename T>
int Vector<T>::capacity() const {
    return capacity_;
}

template <typename T>
bool Vector<T>::empty() const {
    return this->size_ == 0;
}

template <typename T>
T Vector<T>::at(int index) const {
    if (index >= this->size_) {
        throw std::out_of_range("Vector<T>::at() : index out of range");
    }
    return data_[index];
}


template <typename T>
void Vector<T>::push_front(T value) {
    insert(0, value);
}

template <typename T>
void Vector<T>::push_back(T value) {
    insert(this->size_, value);
}

template <typename T>
T Vector<T>::pop_front() {
    T front_value = data_[0];
    erase(0);
    return front_value;
}

template <typename T>
T Vector<T>::pop_back() {
    T back_value = data_[this->size_ - 1];
    erase(this->size_ - 1);
    return back_value;
}


template <typename T>
void Vector<T>::insert(int index, T value) {
    if (index < this->size_) {
        // Insert item at index, shifting the value at that index and
        // all trailing elements right.
        for (int i = this->size_; i > index; i--) {
            data_[i] = data_[i - 1];
        }
    }
    data_[index] = value;
    this->size_++;

    // If the capacity is reached, resize to double the size.
    if (this->size_ == capacity_) {
        resize(capacity_ * 2);
    }
}

template <typename T>
void Vector<T>::erase(int index) {
    if (this->size_ == 0) return;

    if (index < this->size_) {
        // Erase item at index, shifting all trailing elements left
        for (int i = index + 1; i < this->size_; i++) {
            data_[i - 1] = data_[i];
        }
    }
    this->size_--;

    // If size is 1/4 of capactiy, resize to half.
    if (4 * this->size_ <= capacity_) {
        resize(capacity_ / 2);
    }
}

template <typename T>
void Vector<T>::remove(T value) {
    for (int last_found_idx = find(value); last_found_idx != -1; ) {
        erase(last_found_idx);
    }
}

template <typename T>
int Vector<T>::find(T value) {
    for (int i = 0; i < this->size_; i++) {
        if (data_[i] == value) {
            return i;
        }
    }
    return -1;
}


template <typename T>
void Vector<T>::resize(int new_capacity) {
    // Allocate another array of datatype T and migrate the old shit.
    T* new_data = new T[new_capacity];
    for (int i = 0; i < this->size_; i++) {
        new_data[i] = data_[i];
    }

    delete data_;
    data_ = new_data;
    capacity_ = new_capacity;
}


template <typename T>
std::string Vector<T>::ToString() const {
    std::string s;
    for (int i = 0; i < this->size_; i++) {
        s += std::to_string(data_[i]) + " ";
    }
    return s;
}
