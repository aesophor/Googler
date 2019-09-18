// Runtime: 8 ms, faster than 92.46% of C++ online submissions for Two Sum.
// Memory Usage: 10.1 MB, less than 55.86% of C++ online submissions for Two Sum.

class Solution {
 public:
  vector<int> twoSum(vector<int>& nums, int target) {
    // Let current number be a, where a + b == target
    std::unordered_map<int, int> m; // <b, index of a>
    
    for (size_t i = 0; i < nums.size(); i++) {
      int a = nums[i];
      int b = target - a;
      
      auto it = m.find(a);
      if (it != m.end()) {
        return {it->second, i};
      }
      
      m[b] = i;
    }
    
    return {-1, -1};
  }
};
