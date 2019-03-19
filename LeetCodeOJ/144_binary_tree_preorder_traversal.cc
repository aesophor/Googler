// Runtime: 4 ms, faster than 100.00% of C++ online submissions for Binary Tree Preorder Traversal.
// Memory Usage: 9.2 MB, less than 67.43% of C++ online submissions for Binary Tree Preorder Traversal.

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
    vector<int> preorderTraversal(TreeNode* root) {
        preorder(root);
        return result_;
    }
    
private:
    void preorder(TreeNode* node) {
        if (!node) {
            return;
        }
        
        result_.push_back(node->val);
        preorder(node->left);
        preorder(node->right);
    }
    
    vector<int> result_;
};

