#ifndef STACK_H_
#define STACK_H_

#include <string>

template <typename T>
class Stack {
 public:
  Stack();
  virtual ~Stack();

  void push(T val);
  void pop();
  void clear();

  size_t size() const;
  bool empty() const;
  T top() const;
  std::string to_string() const;

 private:
  struct Node {
    Node(T val);
    T val;
    Node* next;
  };

  static const std::string kOutOfRangeMsg_;
  Node* top_;
  size_t size_;
};

#endif // STACK_H_
