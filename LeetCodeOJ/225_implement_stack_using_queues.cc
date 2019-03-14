// Runtime: 4 ms, faster than 100.00% of C++ online submissions for Implement Stack using Queues.
// Memory Usage: 8.9 MB, less than 73.58% of C++ online submissions for Implement Stack using Queues.

class MyStack {
public:
    /** Initialize your data structure here. */
    MyStack() {
        
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        q_.push_back(x);
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int top_element = q_.back();
        q_.pop_back();
        return top_element;
    }
    
    /** Get the top element. */
    int top() {
        return q_.back();
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return q_.empty();
    }
    
private:
    deque<int> q_;
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack obj = new MyStack();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.top();
 * bool param_4 = obj.empty();
 */
