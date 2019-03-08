// Runtime: 24 ms, faster than 99.55% of C++ online submissions for Remove Duplicates from Sorted Array.
// Memory Usage: 10.8 MB, less than 64.45% of C++ online submissions for Remove Duplicates from Sorted Array.

// STL Solution
// nums.erase(std::unique(nums.begin(), nums.end()), nums.end());
// return nums.size();

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }

        int new_idx = 0;
        for (int i = 1; i < nums.size(); i++) {
            if (nums.at(new_idx) != nums.at(i)) {
                new_idx++;
                nums.at(new_idx) = nums.at(i);
            }
        }
        return new_idx + 1;
    }
};
