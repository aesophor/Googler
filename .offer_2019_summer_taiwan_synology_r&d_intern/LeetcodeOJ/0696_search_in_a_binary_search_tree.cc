// Runtime: 48 ms, faster than 95.58% of C++ online submissions for Search in a Binary Search Tree.
// Memory Usage: 29.2 MB, less than 44.82% of C++ online submissions for Search in a Binary Search Tree.

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
  TreeNode* searchBST(TreeNode* root, int val) {
    TreeNode* current = root;
    while (current) {
      if (current->val == val) {
        return current;
      } else if (current->val > val) {
        current = current->left;
      } else { // <
        current = current->right;
      }
    }
    return nullptr;
  }
};
