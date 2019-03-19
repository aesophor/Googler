// Runtime: 4 ms, faster than 100.00% of C++ online submissions for Univalued Binary Tree.
// Memory Usage: 10.9 MB, less than 92.63% of C++ online submissions for Univalued Binary Tree.

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
    bool isUnivalTree(TreeNode* root) {
        if (!root) {
            return result_;
        }
        
        if (!initialized_) {
            root_data_ = root->val;
            initialized_ = true;
        }
        isUnivalTree(root->left);
        isUnivalTree(root->right);
        if (root->val != root_data_) {
            result_ = false;
        }
        return result_;
    }
    
private:
    bool initialized_ = false;
    int root_data_ = 0;
    bool result_ = true;
};
