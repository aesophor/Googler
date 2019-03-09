#ifndef CIRCULAR_BUFFER_HPP_
#define CIRCULAR_BUFFER_HPP_

#include "container.hpp"
#include "linked_list.cpp"
#include <string>

template <typename T>
class CircularBuffer : private LinkedList<T>, virtual public Container<T> {
public:
    CircularBuffer(int size);
    virtual ~CircularBuffer() = default;

    using LinkedList<T>::size;
    using LinkedList<T>::ToString;

    virtual bool empty() const override;
    virtual bool full() const;
    virtual void enqueue(T value);
    virtual T dequeue();
    virtual T peek() const;
};

#endif
