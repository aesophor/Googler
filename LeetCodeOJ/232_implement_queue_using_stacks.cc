// Runtime: 4 ms, faster than 100.00% of C++ online submissions for Implement Queue using Stacks.
// Memory Usage: 9 MB, less than 48.53% of C++ online submissions for Implement Queue using Stacks.

class MyQueue {
public:
    /** Initialize your data structure here. */
    MyQueue() {}
    
    /** Push element x to the back of queue. */
    void push(int x) {
        if (st_.empty()) {
            front_ = x;
        }
        st_.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        vector<int> vec;
        while (!st_.empty()) {
            vec.push_back(st_.top());
            st_.pop();
        }
        
        int ret = vec.back();
        vec.pop_back();
        if (!vec.empty()) {
            front_ = vec.back();
        }
        
        // Restore its content to the stack
        for (int i = vec.size() - 1; i >= 0; i--) {
            st_.push(vec.at(i));
        }
        return ret;
    }
    
    /** Get the front element. */
    int peek() {
        return front_;
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return st_.empty();
    }
    
private:
    stack<int> st_;
    int front_;
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue obj = new MyQueue();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.peek();
 * bool param_4 = obj.empty();
 */
