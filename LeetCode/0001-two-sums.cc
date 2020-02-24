// Runtime: 8 ms, faster than 93.39% of C++ online submissions for Two Sum.
// Memory Usage: 10.2 MB, less than 43.87% of C++ online submissions for Two Sum.

class Solution {
 public:
  vector<int> twoSum(vector<int>& nums, int target) {
    std::unordered_map<int, int> complement_idx;
    
    for (int i = 0; i < nums.size(); i++) {
      auto it = complement_idx.find(target - nums[i]);
      
      if (it != complement_idx.end()) {
        return {it->second, i};
      }
      
      complement_idx.insert({nums[i], i});
    }
    
    return {-1, -1};
  }
};
