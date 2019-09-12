// Runtime: 28 ms, faster than 99.71% of C++ online submissions for Two Sum IV - Input is a BST.
// Memory Usage: 25.1 MB, less than 79.17% of C++ online submissions for Two Sum IV - Input is a BST.

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
  bool findTarget(TreeNode* root, int k) {
    inOrder(root);
    
    int lo = 0;
    int hi = _nums.size() - 1;
    
    if (lo == hi) {
      return false;
    }
    
    while (lo < hi) {
      int sum = _nums[lo] + _nums[hi];
      if (sum < k) {
        lo++;
      } else if (sum > k) {
        hi--;
      } else { // ==
        return true;
      }
    }
    
    return false;
  }
  
 private:
  void inOrder(TreeNode* node) {
    if (!node) {
      return;
    }
    
    inOrder(node->left);
    _nums.push_back(node->val);
    inOrder(node->right);
  }
  
  vector<int> _nums;
};
