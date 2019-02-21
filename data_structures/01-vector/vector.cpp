#include "vector.hpp"
#include <stdexcept>

template <typename T>
Vector<T>::Vector(int initial_capacity) 
    : data_(new T[initial_capacity]), size_(0), capacity_(initial_capacity) {}


template <typename T>
int Vector<T>::size() const {
    return size_;
}

template <typename T>
int Vector<T>::capacity() const {
    return capacity_;
}

template <typename T>
bool Vector<T>::empty() const {
    return size_ == 0;
}

template <typename T>
T Vector<T>::at(int index) const {
    if (index >= size_) {
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
    insert(size_, value);
}

template <typename T>
T Vector<T>::pop_front() {
    T front_value = data_[0];
    erase(0);
    return front_value;
}

template <typename T>
T Vector<T>::pop_back() {
    T back_value = data_[size_ - 1];
    erase(size_ - 1);
    return back_value;
}


template <typename T>
void Vector<T>::insert(int index, T value) {
    if (index < size_) {
        // Insert item at index, shifting the value at that index and
        // all trailing elements right.
        for (int i = size_; i > index; i--) {
            data_[i] = data_[i - 1];
        }
    }
    data_[index] = value;
    size_++;

    // If the capacity is reached, resize to double the size.
    if (size_ == capacity_) {
        resize(capacity_ * 2);
    }
}

template <typename T>
void Vector<T>::erase(int index) {
    if (size_ == 0) return;

    if (index < size_) {
        // Erase item at index, shifting all trailing elements left
        for (int i = index + 1; i < size_; i++) {
            data_[i - 1] = data_[i];
        }
    }
    size_--;

    // If size is 1/4 of capactiy, resize to half.
    if (4 * size_ <= capacity_) {
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
    for (int i = 0; i < size_; i++) {
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
    for (int i = 0; i < size_; i++) {
        new_data[i] = data_[i];
    }

    delete data_;
    data_ = new_data;
    capacity_ = new_capacity;
}


template <typename T>
std::string Vector<T>::ToString() const {
    std::string s;
    for (int i = 0; i < size_; i++) {
        s += std::to_string(data_[i]) + " ";
    }
    return s;
}
