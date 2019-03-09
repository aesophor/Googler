#ifndef CONTAINER_H_
#define CONTAINER_H_

template <typename T>
class Container {
protected:
    Container() : size_(0) {}
    virtual ~Container() = default;

    virtual int size() const = 0;
    virtual bool empty() const = 0;
    virtual T at(int index) const = 0;

    virtual void push_front(T value) = 0;
    virtual void push_back(T value) = 0;
    virtual T pop_front() = 0;
    virtual T pop_back() = 0;

    virtual void insert(int index, T value) = 0;
    virtual void erase(int index) = 0;
    virtual void remove(T value) = 0;
    virtual int find(T value) = 0;
    
    int size_;
};

#endif
