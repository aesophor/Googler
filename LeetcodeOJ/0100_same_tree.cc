// Runtime: 4 ms, faster than 89.61% of C++ online submissions for Same Tree.
// Memory Usage: 10 MB, less than 52.62% of C++ online submissions for Same Tree.

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
  bool isSameTree(TreeNode* p, TreeNode* q) {
    if (!p && !q) {
      return _result;
    }
    
    if ((p && !q) || (!p && q)) {
      _result = false;
      return _result;
    }
    
    if ((p->left && !q->left) || (!p->left && q->left)
       || (p->right && !q->right) || (!p->right && q->right)) {
      _result = false;
      return _result;
    }
    
    if (p->val != q->val) {
      _result = false;
      return _result;
    }
    
    isSameTree(p->left, q->left);
    isSameTree(p->right, q->right);
    return _result;
  }
  
 private:
  bool _result = true;
};
