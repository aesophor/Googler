#ifndef CIRCULAR_BUFFER_H_
#define CIRCULAR_BUFFER_H_

#include "container.h"
#include "linked_list.cc"
#include <string>

template <typename T>
class CircularBuffer : private LinkedList<T>, virtual public Container<T> {
public:
  CircularBuffer(int size);
  virtual ~CircularBuffer() = default;

  using LinkedList<T>::size;
  using LinkedList<T>::ToString;

  virtual bool empty() const override;
  virtual bool full() const;
  virtual void enqueue(T value);
  virtual T dequeue();
  virtual T peek() const;
};

#endif
