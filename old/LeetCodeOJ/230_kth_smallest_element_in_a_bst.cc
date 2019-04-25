// Runtime: 28 ms, faster than 82.65% of C++ online submissions for Kth Smallest Element in a BST.
// Memory Usage: 21.6 MB, less than 46.22% of C++ online submissions for Kth Smallest Element in a BST.

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
  int kthSmallest(TreeNode* root, int k) {
    k_ = k;
    inorder(root);
    return vec_.back();
  }
  
private:
  void inorder(TreeNode* node) {
    if (!node) {
      return;
    }
    
    inorder(node->left);
    if (vec_.empty() || (count_ < k_ && vec_.back() != node->val)) {
      vec_.push_back(node->val);
      count_++;
    }
    if (count_ == k_) {
      return;
    }
    inorder(node->right);
  }
  
  int k_ = 0;
  int count_ = 0;
  vector<int> vec_;
};
