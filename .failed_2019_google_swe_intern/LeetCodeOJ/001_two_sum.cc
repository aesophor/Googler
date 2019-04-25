// Runtime: 8 ms, faster than 99.95% of C++ online submissions for Two Sum.
// Memory Usage: 10.2 MB, less than 53.10% of C++ online submissions for Two Sum.

class Solution {
public:
  vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> complements;

    for (int i = 0; i < nums.size(); i++) {
      if (complements.find(nums.at(i)) != complements.end()) {
        // We’ve found its complement
        return {complements.at(nums.at(i)), i};
      }

      complements[target - nums.at(i)] = i;
    }
    return {-1, -1};
  }
};
