// Runtime: 4 ms, faster than 99.23% of C++ online submissions for Two Sum II - Input array is sorted.
// Memory Usage: 9.6 MB, less than 19.61% of C++ online submissions for Two Sum II - Input array is sorted.

class Solution {
 public:
  vector<int> twoSum(vector<int>& numbers, int target) {
    int lo = 0;
    int hi = numbers.size() - 1;
    
    while (lo <= hi) {
      int sum = numbers[lo] + numbers[hi];
      if (sum < target) {
        lo++;
      } else if (sum > target) {
        hi--;
      } else { // ==
        return {lo + 1, hi + 1};
      }
    }
    
    return {-1, -1};
  }
};
