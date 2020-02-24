// Runtime: 24 ms, faster than 52.69% of C++ online submissions for Majority Element.
// Memory Usage: 11.1 MB, less than 80.30% of C++ online submissions for Majority Element.

class Solution {
 public:
  int majorityElement(vector<int>& nums) {
    std::sort(nums.begin(), nums.end());
    return nums[nums.size() / 2];
  }
};
