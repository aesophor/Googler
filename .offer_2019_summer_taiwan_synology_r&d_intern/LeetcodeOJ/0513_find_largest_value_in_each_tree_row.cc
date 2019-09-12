// Runtime: 12 ms, faster than 98.19% of C++ online submissions for Find Largest Value in Each Tree Row.
// Memory Usage: 21.1 MB, less than 66.92% of C++ online submissions for Find Largest Value in Each Tree Row.

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
  vector<int> largestValues(TreeNode* root) {
    if (!root) {
      return {};
    }
    
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
      int qSize = q.size();
      
      int max = INT_MIN;
      for (int i = 0; i < qSize; i++) {
        TreeNode* node = q.front();
        max = std::max(max, node->val);
        q.pop();
        
        if (node->left) {
          q.push(node->left);
        }
        if (node->right) {
          q.push(node->right);
        }
      }
      _result.push_back(max);
    }
    
    return _result;
  }
  
 private:
  vector<int> _result;
};
