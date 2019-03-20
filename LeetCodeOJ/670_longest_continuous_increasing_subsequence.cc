// Runtime: 16 ms, faster than 98.29% of C++ online submissions for Longest Continuous Increasing Subsequence.
// Memory Usage: 9.6 MB, less than 30.77% of C++ online submissions for Longest Continuous Increasing Subsequence.

class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        
        int start = 0;
        int end = 0;
        int max_len = 0;
        
        for (int i = 0; i < nums.size() - 1; i++) {
            if (nums.at(i) < nums.at(i + 1)) {
                end++;
            } else {
                max_len = std::max(max_len, end - start + 1);
                start = i + 1;
                end = i + 1;
            }
        }
        return std::max(max_len, end - start + 1);
    }
};

// 1 3 5 4 7
//     ^
// 5 > 4
