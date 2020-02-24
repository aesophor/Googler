// Runtime: 4 ms, faster than 65.36% of C++ online submissions for Invert Binary Tree.
// Memory Usage: 10.1 MB, less than 5.45% of C++ online submissions for Invert Binary Tree.

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
  TreeNode* invertTree(TreeNode* root) {
    if (!root) {
      return nullptr;
    }
    
    invertTree(root->left);
    invertTree(root->right);
    swapChildren(root);
    return root;
  }
  
 private:
  TreeNode* swapChildren(TreeNode* node) {
    std::swap(node->left, node->right);
    return node;
  }
};
