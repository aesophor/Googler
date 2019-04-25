// Runtime: 8 ms, faster than 99.93% of C++ online submissions for Two Sum.
// Memory Usage: 10.1 MB, less than 54.90% of C++ online submissions for Two Sum.

class Solution {
 public:
  vector<int> twoSum(vector<int>& nums, int target) {
    std::unordered_map<int, int> complement_idx;
    
    for (size_t i = 0; i < nums.size(); i++) {
      int complement = target - nums[i];
      
      if (complement_idx.find(nums[i]) != complement_idx.end()) {
        return {complement_idx[nums[i]], i};
      }
      
      complement_idx[complement] = i;
    }
    
    return {-1, -1};
  }
};
