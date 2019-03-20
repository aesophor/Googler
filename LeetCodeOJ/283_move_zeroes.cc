// Runtime: 16 ms, faster than 99.68% of C++ online submissions for Move Zeroes.
// Memory Usage: 9.4 MB, less than 98.04% of C++ online submissions for Move Zeroes.

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int new_idx = 0;
        for (int i = 0; i < nums.size(); i++) {
            nums.at(new_idx) = nums.at(i);
            if (nums.at(i) != 0) {
                new_idx++;
            }
        }
        
        while (new_idx < nums.size()) {
            nums.at(new_idx) = 0;
            new_idx++;
        }
    }
};
