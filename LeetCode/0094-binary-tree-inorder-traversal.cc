// Runtime: 4 ms, faster than 60.55% of C++ online submissions for Binary Tree Inorder Traversal.
// Memory Usage: 11.3 MB, less than 5.00% of C++ online submissions for Binary Tree Inorder Traversal.

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
  vector<int> inorderTraversal(TreeNode* root) {
    if (!root) {
      return result_;
    }
    
    inorderTraversal(root->left);
    result_.push_back(root->val);
    inorderTraversal(root->right);
    return result_;
  }
  
 private:
  std::vector<int> result_;
};
