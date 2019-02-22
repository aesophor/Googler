#ifndef STACK_HPP_
#define STACK_HPP_

#include "../vector/vector.cpp"
#include <string>

template <typename T>
class Stack : private Vector<T> {
public:
    Stack() = default;
    virtual ~Stack() = default;

    using Vector<T>::size;
    using Vector<T>::empty;
    using Vector<T>::push_back;
    using Vector<T>::pop_back;

    virtual T top() const;
    virtual std::string ToString() const override;
};

#endif
