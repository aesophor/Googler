// Runtime: 156 ms, faster than 99.02% of C++ online submissions for N-ary Tree Level Order Traversal.
// Memory Usage: 33.9 MB, less than 79.54% of C++ online submissions for N-ary Tree Level Order Traversal.

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
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> result;
        if (!root) {
            return result;
        }
        
        queue<Node*> q;
        q.push(root);
        while (!q.empty()) {
            result.push_back(vector<int>());
            
            int size = q.size();
            for (int i = 0; i < size; i++) {
                result.back().push_back(q.front()->val);
                for (auto child : q.front()->children) {
                    q.push(child);
                }
                q.pop();
            }
        }
        
        return result;
    }
};
