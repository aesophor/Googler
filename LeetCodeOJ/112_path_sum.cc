// Runtime: 16 ms, faster than 99.81% of C++ online submissions for Path Sum.
// Memory Usage: 19.8 MB, less than 59.85% of C++ online submissions for Path Sum.

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
    bool hasPathSum(TreeNode* root, int sum) {
        if (!root) {
            return false;
        }
        
        hasPathSumHelper(root, 0, sum);
        return has_found_target_;
    }
    
private:
    void hasPathSumHelper(TreeNode* node, int num, int target) {
        if (!node) {
            return;
        }
        
        int current_val = num + node->val;
        if (!node->left && !node->right && current_val == target) {
            has_found_target_ = true;
        }
        hasPathSumHelper(node->left, current_val, target);
        hasPathSumHelper(node->right, current_val, target);
    }
    
    bool has_found_target_ = false;
};
