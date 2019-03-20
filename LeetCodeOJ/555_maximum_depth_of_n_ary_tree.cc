// Runtime: 152 ms, faster than 84.90% of C++ online submissions for Maximum Depth of N-ary Tree.
// Memory Usage: 32 MB, less than 76.24% of C++ online submissions for Maximum Depth of N-ary Tree.

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
    int maxDepth(Node* root) {
        if (!root) {
            return 0;
        }
        
        traverse(root, 1);
        return max_depth_;
    }
    
private:
    void traverse(Node* node, int level) {
        if (!node) {
            return;
        }
        
        max_depth_ = std::max(max_depth_, level);
        
        for (auto child : node->children) {
            traverse(child, level + 1);
        }
    }
    
    int max_depth_ = 0;
};
