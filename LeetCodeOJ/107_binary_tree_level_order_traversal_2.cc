// Runtime: 16 ms, faster than 32.69% of C++ online submissions for Binary Tree Level Order Traversal II.
// Memory Usage: 13.8 MB, less than 86.76% of C++ online submissions for Binary Tree Level Order Traversal II.

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> result;
        if (!root) {
            return result;
        }
        
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            result.insert(result.begin(), vector<int>());
            
            int size = q.size();
            for (int i = 0; i < size; i++) {
                // 1. Add its children to the queue.
                if (q.front()->left) {
                    q.push(q.front()->left);
                }
                if (q.front()->right) {
                    q.push(q.front()->right);
                }
                
                // 2. Add this node's value to the vector
                result.front().push_back(q.front()->val);
                
                // 3. Remove it from the queue
                q.pop();
            }
        }
        
        return result;
    }
};
