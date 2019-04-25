// Runtime: 4 ms, faster than 100.00% of C++ online submissions for Second Minimum Node In a Binary Tree.
// Memory Usage: 8.6 MB, less than 96.15% of C++ online submissions for Second Minimum Node In a Binary Tree.

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
  int findSecondMinimumValue(TreeNode* root) {
    first_min_ = root->val;
    traverse(root);
    return (second_min_ != INT_MAX) ? second_min_ : -1;
  }
  
private:
  void traverse(TreeNode* node) {
    if (!node) {
      return;
    }
    
    // The root node will be the smallest,
    // so in the rest of the nodes, we will look for the minimum value.
    if (node->val > first_min_ && node->val < second_min_) {
      second_min_ = node->val;
    }
    
    traverse(node->left);
    traverse(node->right);
  }
  
  int first_min_;
  int second_min_ = INT_MAX;
};
