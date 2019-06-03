// Runtime: 12 ms, faster than 96.78% of C++ online submissions for Path Sum II.
// Memory Usage: 20.3 MB, less than 41.09% of C++ online submissions for Path Sum II.

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
  vector<vector<int>> pathSum(TreeNode* root, int sum) {
    _sum = sum;
    dfs(root);
    return _result;
  }
  
 private:
  void dfs(TreeNode* node) {
    if (!node) {
      return;
    }
    
    _path.push_back(node->val);
    if (!node->left && !node->right) {
      int sum = 0;
      for (auto i : _path) {
        sum += i;
      }
      if (sum == _sum) {
        _result.push_back(_path);
      }
    }
    
    dfs(node->left);
    dfs(node->right);
    
    _path.pop_back();
  }
  
  vector<vector<int>> _result;
  vector<int> _path;
  int _sum;
};
