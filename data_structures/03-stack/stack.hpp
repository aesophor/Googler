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
    virtual T at(int index) const override;

    virtual void push_back(T value) override;
    virtual void push_front(T value) override;
    virtual T pop_front() override;
    virtual T pop_back() override;

    virtual void insert(int index, T value) override;
    virtual void erase(int index) override;
    virtual void remove(T value) override;
    virtual int find(T value) override;

private:
};

#endif
