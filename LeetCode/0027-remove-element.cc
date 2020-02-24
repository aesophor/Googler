// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Remove Element.
// Memory Usage: 8.7 MB, less than 55.88% of C++ online submissions for Remove Element.

class Solution {
 public:
  int removeElement(vector<int>& nums, int val) {
    int slow = 0;
    int fast = 0;
    
    while (fast < nums.size()) {
      if (nums[fast] == val) {
        fast++;
      } else {
        nums[slow] = nums[fast];
        slow++;
        fast++;
      }
    }
    
    return nums.size() - (fast - slow);
  }
};
