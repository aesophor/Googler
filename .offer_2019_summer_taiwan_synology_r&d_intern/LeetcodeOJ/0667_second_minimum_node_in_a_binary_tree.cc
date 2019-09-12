// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Second Minimum Node In a Binary Tree.
// Memory Usage: 8.7 MB, less than 54.95% of C++ online submissions for Second Minimum Node In a Binary Tree.

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
    if (!root) {
      return -1;
    }
    
    bool minInit = false;
    bool min2Init = false;
    int min = 0;
    int min2 = 0;
    
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
      int levelSize = q.size();
      
      for (int i = 0; i < levelSize; i++) {
        TreeNode* node = q.front();
        q.pop();
        
        
        if (!minInit) {
          min = node->val;
          minInit = true;
        } else if (!min2Init && node->val > min) {
          min2 = node->val;
          min2Init = true;
        }
        
        if (node->val < min) {
          min2 = min;
          min = node->val;
        } else if (node->val > min && node->val < min2) {
          min2 = node->val;
        }
        
        
        if (node->left) {
          q.push(node->left);
        }
        if (node->right) {
          q.push(node->right);
        }
      }
    }
    
    return (!min2Init) ? -1 : min2;
  }
};
