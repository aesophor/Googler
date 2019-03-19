// Runtime: 8 ms, faster than 100.00% of C++ online submissions for Sum of Left Leaves.
// Memory Usage: 14.1 MB, less than 38.81% of C++ online submissions for Sum of Left Leaves.

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
    int sumOfLeftLeaves(TreeNode* root) {
        postOrder(root);
        return sum_;
    }
    
private:
    int postOrder(TreeNode* node) {
        if (!node) {
            return 0;
        }
        
        int left_val = postOrder(node->left);
        if (node->left && !node->left->left && !node->left->right) {
            sum_ += left_val;
        }
        postOrder(node->right);
        return node->val;
    }
    
    int sum_ = 0;
};
