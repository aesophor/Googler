// Runtime: 24 ms, faster than 99.60% of C++ online submissions for Binary Tree Tilt.
// Memory Usage: 22.1 MB, less than 68.42% of C++ online submissions for Binary Tree Tilt.

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
    int findTilt(TreeNode* root) {
        sumSubtree(root);
        return result_;
    }

private:
    int sumSubtree(TreeNode* root) {
        if (!root) {
            return 0;
        }

        // This problem can be reduced to "sum a tree using postorder and recursion".
        // Look at this, we want to get the sum of entire left subtree, right?
        // So we have to return root->left's left subtree + root->left + root_left's right subtree
        int left_subtree_sum = sumSubtree(root->left);
        int right_subtree_sum = sumSubtree(root->right);
        result_ += std::abs(left_subtree_sum - right_subtree_sum);
        return left_subtree_sum + root->val + right_subtree_sum;
    }

    int result_ = 0;
};
