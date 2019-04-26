// Runtime: 36 ms, faster than 83.89% of C++ online submissions for Min Stack.
// Memory Usage: 17.3 MB, less than 9.14% of C++ online submissions for Min Stack.

class MinStack {
 private:
  struct Node {
    Node(int val) : val(val), next() {}
    int val;
    Node* next;
  };
  
  Node* top_;
  int min_;
  
 public:
  /** initialize your data structure here. */
  MinStack() : top_(), min_(INT_MAX) {}
    
  void push(int x) {
    Node* new_node = new Node(x);
    min_ = std::min(min_, x);
    
    if (!top_) {
      top_ = new_node;
    } else {
      new_node->next = top_;
      top_ = new_node;
    }
  }
  
  void pop() {
    if (top_) {
      if (!top_->next) {
        //delete top_;
        top_ = nullptr;
        min_ = INT_MAX;
      } else {
        Node* old_top = top_;
        top_ = top_->next;
        //delete old_top;
        
        Node* ptr = top_;
        min_ = INT_MAX;
        while (ptr) {
          min_ = std::min(ptr->val, min_);
          ptr = ptr->next;
        }
      }
    }
  }
    
  int top() {
    return top_->val;
  }
    
  int getMin() {
    return min_;
  }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
