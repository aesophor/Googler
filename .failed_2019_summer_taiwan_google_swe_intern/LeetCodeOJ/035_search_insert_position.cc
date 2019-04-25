// Runtime: 8 ms, faster than 99.05% of C++ online submissions for Search Insert Position.
// Memory Usage: 9.3 MB, less than 11.30% of C++ online submissions for Search Insert Position.

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        for (int i = 0; i < nums.size(); i++) {
            if (nums.at(i) == target || nums.at(i) > target) {
                return i;
            }
        }
        return nums.size();
    }
};
