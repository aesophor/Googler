#include "stack.h"
#include <stdexcept>

template <typename T>
T Stack<T>::top() const {
    if (!this->size_ == 0) {
        throw std::out_of_range("Stack<T>::top() : index out of range");
    }
    return this->data_[0];
}

template <typename T>
std::string Stack<T>::ToString() const {
    std::string s;
    for (int i = this->size_ - 1; i >= 0; i--) {
        s += std::to_string(this->data_[i]) + " ";
    }
    return s;
}
