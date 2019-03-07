// Runtime: 4 ms, faster than 100.00% of C++ online submissions for Remove Element.
// Memory Usage: 9.4 MB, less than 5.45% of C++ online submissions for Remove Element.

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int shift_left_offset = 0;
        
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == val) {
                shift_left_offset++;
            } else if (shift_left_offset > 0) {
                nums[i - shift_left_offset] = nums[i];
            }
        }
        
        return nums.size() - shift_left_offset;
    }
};
