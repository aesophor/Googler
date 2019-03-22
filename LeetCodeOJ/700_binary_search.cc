// Runtime: 52 ms, faster than 68.41% of C++ online submissions for Binary Search.
// Memory Usage: 11 MB, less than 96.53% of C++ online submissions for Binary Search.

class Solution {
public:
  int search(vector<int>& nums, int target) {
    int left = 0;
    int right = nums.size() - 1;
    
    while (left <= right) {
      int mid = left + (right - left) / 2;
      if (nums.at(mid) < target) {
        left = mid + 1;
      } else if (nums.at(mid) > target) {
        right = mid - 1;
      } else { // equals
        return mid;
      }
    }
    return -1;
  }
};
