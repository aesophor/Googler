// Runtime: 236 ms, faster than 6.27% of C++ online submissions for N-ary Tree Preorder Traversal.
// Memory Usage: 128.9 MB, less than 5.55% of C++ online submissions for N-ary Tree Preorder Traversal.

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
    vector<int> preorder(Node* root) {
        if (!root) {
            return result_;
        }
        
        result_.push_back(root->val);
        for (auto child : root->children) {
            preorder(child);
        }
        return result_;
    }

private:
    vector<int> result_;
};
