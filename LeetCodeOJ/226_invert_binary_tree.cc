// Runtime: 4 ms, faster than 100.00% of C++ online submissions for Invert Binary Tree.
// Memory Usage: 8.9 MB, less than 100.00% of C++ online submissions for Invert Binary Tree.

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
      return root;
    }
    std::swap(root->left, root->right);
    invertTree(root->left);
    invertTree(root->right);
    return root;
  }
};
