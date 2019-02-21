#ifndef STACK_HPP_
#define STACK_HPP_

#include "container.hpp"
#include <string>

template <typename T>
class Stack : public Container<T> {
public:
    Stack();
    virtual ~Stack() = default;

    virtual int size() const override;
    virtual bool empty() const override;

    T top() const;
    void push(T value);
    T pop();

    std::string ToString() const;

protected:
    virtual T at(int index) const {}

    virtual void push_back(T value) {}
    virtual void push_front(T value) {}
    virtual T pop_front() {}
    virtual T pop_back() {}

    virtual void insert(int index, T value) {}
    virtual void erase(int index) {}
    virtual void remove(T value) {}
    virtual int find(T value) {}

private:
    struct Node {
        Node(T value) : data(value) {}
        Node* next;
        T data;
    };

    Stack::Node* top_;
};

#endif
