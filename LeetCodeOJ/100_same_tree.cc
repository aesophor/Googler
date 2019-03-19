// Runtime: 4 ms, faster than 100.00% of C++ online submissions for Same Tree.
// Memory Usage: 10.6 MB, less than 5.54% of C++ online submissions for Same Tree.

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
        inorder(p);
        vector<int> p_inorder = result_;

        result_.clear();
        inorder(q);

        if (p_inorder != result_) {
            return false;
        }

        result_.clear();
        postOrder(p);
        vector<int> p_postorder = result_;

        result_.clear();
        postOrder(q);

        return p_postorder == result_;
    }

private:
    void inorder(TreeNode* node) {
        if (!node) {
            result_.push_back(0);
            return;
        }

        inorder(node->left);
        result_.push_back(node->val);
        inorder(node->right);
    }

    void postOrder(TreeNode* node) {
        if (!node) {
            result_.push_back(0);
            return;
        }

        postOrder(node->left);
        postOrder(node->right);
        result_.push_back(node->val);
    }

    vector<int> result_;
};
