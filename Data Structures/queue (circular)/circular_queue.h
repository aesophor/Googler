#ifndef CIRCULAR_QUEUE_H_
#define CIRCULAR_QUEUE_H_

#include <string>
#include <memory>

#define DEFAULT_CAPACITY 5

template <typename T>
class CircularQueue {
 public:
  CircularQueue(int capacity=DEFAULT_CAPACITY);
  virtual ~CircularQueue() = default;

  void push(T val);
  void pop();
  void clear();

  size_t size() const;
  bool empty() const;
  bool full() const;
  T front() const;
  std::string to_string() const;

 private:
  std::unique_ptr<T[]> data_;
  int head_;
  int tail_;
  const size_t size_;
};

#endif // CIRCULAR_QUEUE_H_
