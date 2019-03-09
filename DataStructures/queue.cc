#include "queue.h"

template <typename T>
void Queue<T>::enqueue(T value) {
    this->push_back(value);
}

template <typename T>
T Queue<T>::dequeue() {
    return this->pop_front();
}

template <typename T>
T Queue<T>::peek() const {
    return this->front();
}
