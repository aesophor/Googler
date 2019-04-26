#ifndef VECTOR_H_
#define VECTOR_H_

#include <string>

#define DEFAULT_SIZE 4

template <typename T>
class Vector {
 public:
  Vector(int init_capacity=DEFAULT_SIZE);
  virtual ~Vector();

  void push_back(T val);
  void push_front(T val);
  void pop_back();
  void pop_front();

  // Insert val at the specified index, shifting
  // the remaining elements to the right.
  void insert(size_t index, T val);
  void erase(size_t index);
  void remove(T val);
  size_t find(T val);
  void clear();

  size_t size() const;
  bool empty() const;
  T at(size_t index) const;
  T front() const;
  T back() const;
  size_t capacity() const;
  std::string to_string() const;

 private:
  void resize(size_t new_capacity);

  static const std::string kOutOfRangeMsg_;
  T* data_;
  size_t size_;
  size_t capacity_;
};

#endif // VECTOR_H_
