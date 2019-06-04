// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Symmetric Tree.
// Memory Usage: 14.7 MB, less than 80.33% of C++ online submissions for Symmetric Tree.

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
  bool isSymmetric(TreeNode* root) {
    if (!root) {
      return true;
    }
    return isMirror(root->left, root->right);
  }
  
 private:
  bool isMirror(TreeNode* n1, TreeNode* n2) {
    if (!n1 && !n2) return true;
    if (!n1 || !n2) return false;
    // both n1 and n2 exists
    return n1->val == n2->val
        && isMirror(n1->left, n2->right)
        && isMirror(n1->right, n2->left);
  }
};
