// Runtime: 8 ms, faster than 100.00% of C++ online submissions for Binary Tree Level Order Traversal.
// Memory Usage: 13.7 MB, less than 94.81% of C++ online submissions for Binary Tree Level Order Traversal.

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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if (!root) {
            return result;
        }
        
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            result.push_back(vector<int>());
            
            int size = q.size();
            for (int i = 0; i < size; i++) {
                result.back().push_back(q.front()->val);
                if (q.front()->left) {
                    q.push(q.front()->left);
                }
                if (q.front()->right) {
                    q.push(q.front()->right);
                }
                q.pop();
            }
        }
        
        return result;
    }
};
