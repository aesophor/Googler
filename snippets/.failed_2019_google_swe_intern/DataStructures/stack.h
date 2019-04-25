#ifndef STACK_H_
#define STACK_H_

#include "vector.cc"
#include <string>

template <typename T>
class Stack : private Vector<T>, virtual public Container<T> {
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
