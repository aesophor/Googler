// Runtime: 8 ms, faster than 93.39% of C++ online submissions for Two Sum.
// Memory Usage: 10.2 MB, less than 43.87% of C++ online submissions for Two Sum.

// 1. 暴力法： time = O(n^2), space = O(1)
// 2. unordered_map： time = O(n), space = O(n)

// 思路：
// 假设我们要在 [2,7,11,15] 中找到两数，使两数的和 = 18,
// 我们只需要遍历一次这个 array 即可。
// 首先建立一个 unordered_map
// 到 2 的时候，我们到 unordered_map 查找 18-2 是否存在？ 不存在，我们记录下 2 出现过，其 index = 0
// 到 7 的时候，我们到 unordered_map 查找 18-7 是否存在？ 不存在，我们记录下 7 出现过，其 index = 1
// 到 11 的时候，我们到 unordered_map 查找 18-11 是否存在？ 存在，7 曾出现在 index = 1。返回 {1, 2}

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
