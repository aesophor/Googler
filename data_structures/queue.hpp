#ifndef QUEUE_HPP_
#define QUEUE_HPP_

#include "linked_list.cpp"
#include <string>

template <typename T>
class Queue : private LinkedList<T>, virtual public Container<T> {
public:
    Queue() = default;
    virtual ~Queue() = default;

    using LinkedList<T>::size;
    using LinkedList<T>::empty;
    using LinkedList<T>::ToString;
    
    virtual void enqueue(T value);
    virtual T dequeue();
    virtual T peek() const;
};

#endif
