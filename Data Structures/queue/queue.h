#ifndef QUEUE_H_
#define QUEUE_H_

#include <string>

template <typename T>
class Queue {
 public:
  Queue();
  virtual ~Queue();

  void push(T val);
  void pop();
  void clear();

  size_t size() const;
  bool empty() const;
  T front() const;
  std::string to_string() const;

 private:
  struct Node {
    Node(T val);
    T val;
    Node* next;
  };

  static const std::string kOutOfRangeMsg_;
  Node* head_;
  Node* tail_;
  size_t size_;
};

#endif // QUEUE_H_
