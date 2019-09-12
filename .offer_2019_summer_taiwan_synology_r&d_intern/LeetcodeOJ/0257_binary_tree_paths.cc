// Runtime: 4 ms, faster than 93.99% of C++ online submissions for Binary Tree Paths.
// Memory Usage: 10.9 MB, less than 93.73% of C++ online submissions for Binary Tree Paths.

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
  vector<string> binaryTreePaths(TreeNode* root) {
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
      _result.push_back(pathToString());
    }
    
    dfs(node->left);
    dfs(node->right);
    _path.pop_back();
  }
  
  string pathToString() {
    string result;
    for (int i = 0; i < _path.size(); i++) {
      result += std::to_string(_path[i]);
      result += (i == _path.size() - 1) ? "" : "->";
    }
    return result;
  }
  
  vector<int> _path;
  vector<string> _result;
};
