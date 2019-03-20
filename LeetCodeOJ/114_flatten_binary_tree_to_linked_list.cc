// Runtime: 8 ms, faster than 100.00% of C++ online submissions for Flatten Binary Tree to Linked List.
// Memory Usage: 11.5 MB, less than 5.00% of C++ online submissions for Flatten Binary Tree to Linked List.

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
    void flatten(TreeNode* root) {
        preOrder(root); // 1 2 3 4 5 6
        
        for (int i = 0; i < order_.size(); i++) {
            order_.at(i)->left = nullptr;
            order_.at(i)->right = (i < order_.size() - 1) ? order_.at(i + 1) : nullptr;
        }
    }

private:
    void preOrder(TreeNode* node) {
        if (!node) {
            return;
        }
        
        order_.push_back(node);
        preOrder(node->left);
        preOrder(node->right);
    }

    vector<TreeNode*> order_;
};
