#include "stack.hpp"
#include <stdexcept>

template <typename T>
Stack<T>::Stack() : Container<T>(), top_() {}


template <typename T>
int Stack<T>::size() const {
    return this->size_;
}

template <typename T>
bool Stack<T>::empty() const {
    return this->size_ == 0;
}


template <typename T>
T Stack<T>::top() const {
    if (!top_) {
        throw std::out_of_range("Stack<T>::top() : index out of range");
    }
    return top_->data;
}

template <typename T>
void Stack<T>::push(T value) {
    Node* new_node = new Node(value);
    new_node->next = top_;
    top_ = new_node;
}

template <typename T>
T Stack<T>::pop() {
    if (!top_) {
        throw std::out_of_range("Stack<T>::top() : index out of range");
    }

    Node* old_top = top_;
    T top_value = old_top->data;

    top_ = top_->next;
    delete old_top;
}


template <typename T>
std::string Stack<T>::ToString() const {
    std::string s;
    for (Node* ptr = top_; ptr; ptr = ptr->next) {
        s += std::to_string(ptr->data) + " ";
    }
    return s;
}
