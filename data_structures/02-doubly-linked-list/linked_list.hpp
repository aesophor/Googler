#ifndef LINKED_LIST_HPP_
#define LINKED_LIST_HPP_

#include <string>

template <typename T>
class LinkedList {
public:
    LinkedList();
    ~LinkedList() = default;

    int size() const;
    bool empty() const;
    T at(int index) const;
    T front() const;
    T back() const;

    void push_front(T value);
    void push_back(T value);
    T pop_front();
    T pop_back();

    void insert(int index, T value);
    void erase(int index);
    void remove_value(T value);
    void reverse();

    std::string ToString() const;

private:
    struct Node {
        Node(T value) : prev(), next(), data(value) {}
        ~Node() {}
        Node* prev;
        Node* next;
        T data;
    };

    LinkedList::Node* head_;
    LinkedList::Node* tail_;
    int size_;
};

#endif
