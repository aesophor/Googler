#include "min_stack.h"

#include <climits>
#include <algorithm>

MinStack::Node::Node(int val) : val(val), next() {}

MinStack::MinStack() : top_(), min_(INT_MAX) {}

MinStack::~MinStack() {
  while (top_) {
    Node* next = top_->next;
    delete top_;
    top_ = next;
  }
}


void MinStack::push(int x) {
  Node* new_node = new Node(x);
  min_ = std::min(min_, x);

  if (!top_) {
    top_ = new_node;
  } else {
    new_node->next = top_;
    top_ = new_node;
  }
}

void MinStack::pop() {
  if (top_) {
    if (!top_->next) {
      delete top_;
      top_ = nullptr;
      min_ = INT_MAX;
    } else {
      Node* old_top = top_;
      top_ = top_->next;
      delete old_top;

      Node* ptr = top_;
      min_ = INT_MAX;
      while (ptr) {
        min_ = std::min(ptr->val, min_);
        ptr = ptr->next;
      }
    }
  }
}

int MinStack::top() const {
  return top_->val;
}

int MinStack::get_min() const {
  return min_;
}
