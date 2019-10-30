// Runtime: 8 ms, faster than 84.93% of C++ online submissions for Find First and Last Position of Element in Sorted Array.
// Memory Usage: 10.2 MB, less than 100.00% of C++ online submissions for Find First and Last Position of Element in Sorted Array.

class Solution {
 public:
  vector<int> searchRange(vector<int>& nums, int target) {
    if (nums.empty()) {
      return {-1, -1};
    }
    
    int begin = bSearchBeginPos(nums, target);
    if (begin == -1) {
      return {-1, -1};
    }
    
    int end = begin;
    while (end < nums.size() && nums[end] == target) {
      end++;
    }
    end--;
    
    return {begin, end};
  }
  
 private:
  int bSearchBeginPos(vector<int>& nums, int target) {
    int lo = 0;
    int hi = nums.size() - 1;
    
    // Find begin pos
    while (lo <= hi) {
      int mid = lo + (hi - lo) / 2;
      
      if (nums[mid] < target) {
        lo = mid + 1;
      } else if (nums[mid] >= target) {
        hi = mid - 1;
      }
    }
    
    return (hi + 1 < nums.size() && nums[hi + 1] == target) ? hi + 1 : -1;
  }
};
