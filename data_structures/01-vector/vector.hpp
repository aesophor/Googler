#ifndef VECTOR_HPP_
#define VECTOR_HPP_

#include <string>

#define DEFAULT_SIZE 4

template <typename T>
class Vector {
public:
    Vector(int initial_capacity=DEFAULT_SIZE);
    ~Vector() = default;

    int size() const;
    int capacity() const;
    bool empty() const;
    T at(int index) const;

    void push_back(T value);
    void push_front(T value);
    T pop_front();
    T pop_back();

    void insert(int index, T value);
    void erase(int index);
    void remove(T value);
    int find(T value);

    std::string ToString() const;

private:
    void resize(int new_capacity);

    T* data_;
    int size_;
    int capacity_;
};

#endif
