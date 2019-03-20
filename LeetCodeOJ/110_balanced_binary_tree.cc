// Runtime: 20 ms, faster than 70.02% of C++ online submissions for Balanced Binary Tree.
// Memory Usage: 17.2 MB, less than 83.02% of C++ online submissions for Balanced Binary Tree.

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
    bool isBalanced(TreeNode* root) {
        if (!root) {
            return is_balanced_;
        }
        
        if (std::abs(getDepth(root->left, 1) - getDepth(root->right, 1)) > 1) {
            is_balanced_ = false;
            return false; // 發現 > 1 就不要繼續遞回了，不然call stack會炸掉
        }
        isBalanced(root->left);
        isBalanced(root->right);
        return is_balanced_;
    }
    
private:
    int getDepth(TreeNode* node, int level) {
        if (!node) {
            return level - 1;
        }
        
        int left_depth = getDepth(node->left, level + 1);
        int right_depth = getDepth(node->right, level + 1);
        return std::max(left_depth, right_depth);
    }
    
    bool is_balanced_ = true;
};
