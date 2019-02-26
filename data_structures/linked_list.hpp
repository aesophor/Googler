#ifndef LINKED_LIST_HPP_
#define LINKED_LIST_HPP_

#include "container.hpp"
#include <string>

template <typename T>
class LinkedList : public Container<T> {
public:
    LinkedList();
    virtual ~LinkedList() = default;

    virtual int size() const override;
    virtual bool empty() const override;
    virtual T at(int index) const override;
    
    virtual void push_front(T value) override;
    virtual void push_back(T value) override;
    virtual T pop_front() override;
    virtual T pop_back() override;

    virtual void insert(int index, T value) override;
    virtual void erase(int index) override;
    virtual void remove(T value) override;
    virtual int find(T value) override;

    T front() const;
    T back() const;
    void reverse();
    std::string ToString() const;

protected:
    struct Node {
        Node(T value) : prev(), next(), data(value) {}
        ~Node() {}
        Node* prev;
        Node* next;
        T data;
    };

    LinkedList::Node* head_;
    LinkedList::Node* tail_;
};

#endif
