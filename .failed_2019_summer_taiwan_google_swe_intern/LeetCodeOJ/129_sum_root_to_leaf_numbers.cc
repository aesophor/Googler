// Runtime: 4 ms, faster than 100.00% of C++ online submissions for Sum Root to Leaf Numbers.
// Memory Usage: 12.4 MB, less than 72.61% of C++ online submissions for Sum Root to Leaf Numbers.

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
    int sumNumbers(TreeNode* root) {
        if (!root) {
            return 0;
        }
        
        traverse(root, 0);
        return sum_;
    }
    
private:
    void traverse(TreeNode* node, int num) {
        if (!node) {
            return;
        }
        
        int current_val = num * 10 + node->val;
        if (!node->left && !node->right) {
            sum_ += current_val;
        }
        traverse(node->left, current_val);
        traverse(node->right, current_val);
    }
    
    int sum_ = 0;
};
