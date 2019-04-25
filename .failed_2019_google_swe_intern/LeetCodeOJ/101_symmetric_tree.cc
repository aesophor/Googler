// Runtime: 12 ms, faster than 96.35% of C++ online submissions for Symmetric Tree.
// Memory Usage: 15.6 MB, less than 98.01% of C++ online submissions for Symmetric Tree.

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
  bool isMirror(TreeNode* node1, TreeNode* node2) const {
    if (!node1 && !node2) {
      return true;
    } else if ((!node1 && node2) || (node1 && !node2)) {
      return false;
    } else {
      return node1->val == node2->val
        && isMirror(node1->left, node2->right)
        && isMirror(node1->right, node2->left);
    }
  }
};
