// Runtime: 8 ms, faster than 99.57% of C++ online submissions for Cousins in Binary Tree.
// Memory Usage: 11.7 MB, less than 85.40% of C++ online submissions for Cousins in Binary Tree.

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
    bool isCousins(TreeNode* root, int x, int y) {
        if (!root) {
            return false;
        }
        
        x_ = x;
        y_ = y;
        helper(root, nullptr, 1);
        return x_level_ == y_level_ && x_parent_ != y_parent_;
    }
    
private:
    void helper(TreeNode* node, TreeNode* parent, int level) {
        if (!node) {
            return;
        }
        
        if (node->val == x_) {
            x_parent_ = parent;
            x_level_ = level;
        }
        if (node->val == y_) {
            y_parent_ = parent;
            y_level_ = level;
        }
        helper(node->left, node, level + 1);
        helper(node->right, node, level + 1);
    }
    
    TreeNode* x_parent_ = nullptr;
    TreeNode* y_parent_ = nullptr;
    int x_ = 0;
    int y_ = 0;
    int x_level_ = 0;
    int y_level_ = 0;
};
