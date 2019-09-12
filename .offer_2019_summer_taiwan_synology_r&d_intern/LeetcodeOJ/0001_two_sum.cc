// Runtime: 4 ms, faster than 99.94% of C++ online submissions for Two Sum.
// Memory Usage: 10.3 MB, less than 23.46% of C++ online submissions for Two Sum.

class Solution {
 public:
  vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> m;
    for (int i = 0; i < nums.size(); i++) {
      if (m.find(target - nums[i]) != m.end()) {
        return {m[target - nums[i]], i};
      }
      m.insert({nums[i], i});
    }
    return {-1, -1};
  }
};
