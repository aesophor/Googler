// Runtime: 8 ms, faster than 99.77% of C++ online submissions for Leaf-Similar Trees.
// Memory Usage: 13.9 MB, less than 72.31% of C++ online submissions for Leaf-Similar Trees.

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
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        inorder(root1);
        vector<int> leaves1 = leaves_;
        
        leaves_.clear();
        inorder(root2);
        vector<int> leaves2 = leaves_;
        return leaves1 == leaves2;
    }
    
private:
    void inorder(TreeNode* node) {
        if (!node) {
            return;
        }
        
        inorder(node->left);
        if (!node->left && !node->right) {
            leaves_.push_back(node->val);
        }
        inorder(node->right);
    }
    
    vector<int> leaves_;
};
