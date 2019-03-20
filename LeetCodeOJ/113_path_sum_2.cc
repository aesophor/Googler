// Runtime: 20 ms, faster than 79.37% of C++ online submissions for Path Sum II.
// Memory Usage: 19.9 MB, less than 70.07% of C++ online submissions for Path Sum II.

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
        if (!root) {
            return paths_;
        }
        
        pathSumHelper(root, 0, path_, sum);
        return paths_;
    }
    
private:
    void pathSumHelper(TreeNode* node, int num, vector<int>& path, int target) {
        if (!node) {
            return;
        }
        
        int current_val = num + node->val;
        path.push_back(node->val);
        if (!node->left && !node->right && current_val == target) {
            paths_.push_back(path);
        }
        pathSumHelper(node->left, current_val, path, target);
        pathSumHelper(node->right, current_val, path, target);
        path.pop_back();
    }
    
    vector<int> path_; // current path cache
    vector<vector<int>> paths_;
};
