#include "circular_buffer.hpp"

template <typename T>
CircularBuffer<T>::CircularBuffer(int size) : LinkedList<T>() {
    for (int i = 0; i < size; i++) {
        this->push_back(0);
    }
    this->tail_->next = this->head_;
    this->head_->prev = this->tail_;
    this->tail_ = this->head_;
    this->size_ = size;
}


template <typename T>
bool CircularBuffer<T>::empty() const {
    return this->head_ == this->tail_;
}

template <typename T>
bool CircularBuffer<T>::full() const {
    return this->tail_->next == this->head_;
}

template <typename T>
void CircularBuffer<T>::enqueue(T value) {
    // Write the value to where the tail_ is, and increment tail_.
    this->tail_->data = value;
    if (full()) {
        this->head_ = this->head_->next;
    }
    this->tail_ = this->tail_->next;
    this->tail_->data = 0;
}

template <typename T>
T CircularBuffer<T>::dequeue() {
    T value = this->head_->data;
    this->head_->data = 0;
    this->head_ = this->head_->next;
    return value;
}

template <typename T>
T CircularBuffer<T>::peek() const {
    return this->head_->data;
}
