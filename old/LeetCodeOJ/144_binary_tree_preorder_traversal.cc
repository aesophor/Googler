// Runtime: 4 ms, faster than 100.00% of C++ online submissions for Binary Tree Preorder Traversal.
// Memory Usage: 9.1 MB, less than 92.71% of C++ online submissions for Binary Tree Preorder Traversal.

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
    vector<int> preorderTraversal(TreeNode* root) {
        preorder(root);
        return result_;
    }
    
private:
    void preorder(TreeNode* node) {
        if (!node) {
            return;
        }
        
        result_.push_back(node->val);
        preorder(node->left);
        preorder(node->right);
    }
    
    vector<int> result_;
};


// Iteration
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
  vector<int> preorderTraversal(TreeNode* root) {
    if (!root) {
      return {};
    }

    // To perform a DFS with iteration, we will use a stack.
    vector<int> result;
    stack<TreeNode*> st;
    st.push(root);

    while (!st.empty()) {
      TreeNode* top = st.top();
      st.pop();
      result.push_back(top->val);

      if (top->right) {
        st.push(top->right);
      }

      if (top->left) {
        st.push(top->left);
      }
    }

    return result;
  }
};

