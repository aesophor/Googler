#ifndef STACK_HPP_
#define STACK_HPP_

#include "../01-vector/vector.cpp"
#include <string>

template <typename T>
class Stack : private Vector<T> {
public:
    Stack();
    virtual ~Stack() = default;

    T top() const;
    using Vector<T>::size;
    using Vector<T>::empty;
    using Vector<T>::push_back;
    using Vector<T>::pop_back;

    virtual std::string ToString() const override;
};

#endif
