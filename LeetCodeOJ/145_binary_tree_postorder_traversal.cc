// Runtime: 4 ms, faster than 100.00% of C++ online submissions for Binary Tree Postorder Traversal.
// Memory Usage: 11.2 MB, less than 5.10% of C++ online submissions for Binary Tree Postorder Traversal.

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
    vector<int> postorderTraversal(TreeNode* root) {
        if (!root) {
            return result_;
        }
        
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        result_.push_back(root->val);
        return result_;
    }
    
private:
    vector<int> result_;
};
