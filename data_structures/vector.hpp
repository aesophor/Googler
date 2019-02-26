#ifndef VECTOR_HPP_
#define VECTOR_HPP_

#include "container.hpp"
#include <string>

#define DEFAULT_SIZE 4

template <typename T>
class Vector : public Container<T> {
public:
    Vector(int initial_capacity=DEFAULT_SIZE);
    virtual ~Vector() = default;

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

    int capacity() const;
    virtual std::string ToString() const;

protected:
    void resize(int new_capacity);

    T* data_;
    int capacity_;
};

#endif
