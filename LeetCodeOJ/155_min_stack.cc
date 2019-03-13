// Runtime: 36 ms, faster than 87.81% of C++ online submissions for Min Stack.
// Memory Usage: 17.2 MB, less than 12.10% of C++ online submissions for Min Stack.

class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() : top_(), min_data_(0) {}
    
    void push(int x) {
        if (!top_) {
            min_data_ = x;
        } else {
            min_data_ = std::min(min_data_, x);
        }
        
        MinStack::Node* new_node = new MinStack::Node(x);
        new_node->next = top_;
        top_ = new_node;
    }
    
    void pop() {
        MinStack::Node* old_top = top_;
        top_ = top_->next;
        delete old_top;
        
        if (top_) {
            min_data_ = top_->data;
        }
        
        // Get the new min
        MinStack::Node* ptr = top_;
        while (ptr) {
            min_data_ = std::min(min_data_, ptr->data);
            ptr = ptr->next;
        }
    }
    
    int top() {
        return top_->data;
    }
    
    int getMin() {
        return min_data_;
    }
    
private:
    struct Node {
        Node(int data) : data(data) {}
        int data;
        Node* next;
    };
    
    MinStack::Node* top_;
    int min_data_;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */
