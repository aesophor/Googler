// Runtime: 8 ms, faster than 88.80% of C++ online submissions for Search Insert Position.
// Memory Usage: 8.9 MB, less than 77.23% of C++ online submissions for Search Insert Position.

class Solution {
 public:
  int searchInsert(vector<int>& nums, int target) {
    int lo = 0;
    int hi = nums.size() - 1;
    
    while (lo <= hi) {
      int mid = (lo + hi) / 2;
      if (nums[mid] < target) {
        lo = mid + 1;
      } else if (nums[mid] >= target) {
        hi = mid - 1;
      }
    }
    
    return hi + 1;
  }
};
