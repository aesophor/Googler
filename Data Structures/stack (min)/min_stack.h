// Runtime: 36 ms, faster than 83.89% of C++ online submissions for Min Stack.
// Memory Usage: 17.3 MB, less than 9.14% of C++ online submissions for Min Stack.

#ifndef MIN_STACK_H_
#define MIN_STACK_H_

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
class MinStack {
 public:
  MinStack();
  virtual ~MinStack();

  void push(int x);
  void pop();
  int top() const;
  int get_min() const;

 private:
  struct Node {
    Node(int val);
    int val;
    Node* next;
  };
  
  Node* top_;
  int min_;
};

#endif // MIN_STACK_H_
