// Runtime: 220 ms, faster than 10.71% of C++ online submissions for N-ary Tree Postorder Traversal.
// Memory Usage: 127.7 MB, less than 5.60% of C++ online submissions for N-ary Tree Postorder Traversal.

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution {
public:
    vector<int> postorder(Node* root) {
        if (!root) {
            return result_;
        }
        
        // Traverse the children from left -> right
        for (auto child : root->children) {
            postorder(child);
        }
        result_.push_back(root->val);
        return result_;
    }
    
private:
    vector<int> result_;
};
