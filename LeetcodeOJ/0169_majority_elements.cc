// Runtime: 20 ms, faster than 92.83% of C++ online submissions for Majority Element.
// Memory Usage: 11.2 MB, less than 45.89% of C++ online submissions for Majority Element.

class Solution {
 public:
  int majorityElement(vector<int>& nums) {
    std::sort(nums.begin(), nums.end());
    return nums[nums.size() / 2];
  }
};

// more than floor(n/2)

// case1-1: even
// [1,1,2,2,2,2]
//      =======

// case1-2: odd
// [1,1,1,2,2,2,2]
//        =======

// case2-1: even
// [1,1,1,1,2,2]
//  =======

// case2-2: odd
// [1,1,1,1,2,2,2]
//  =======
