// Runtime: 4 ms, faster than 100.00% of C++ online submissions for Binary Tree Inorder Traversal.
// Memory Usage: 9.2 MB, less than 71.97% of C++ online submissions for Binary Tree Inorder Traversal.

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
    vector<int> inorderTraversal(TreeNode* root) {
        inorder(root);
        return result_;
    }
    
private:
    void inorder(TreeNode* root) {
        if (!root) {
            return;
        }
        
        inorder(root->left);
        result_.push_back(root->val);
        inorder(root->right);
    }
    
    vector<int> result_;
};
