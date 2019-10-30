// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Remove Element.
// Memory Usage: 8.7 MB, less than 63.23% of C++ online submissions for Remove Element.

class Solution {
 public:
  int removeElement(vector<int>& nums, int val) {
    int p1 = 0;
    int p2 = 0;
    
    for (; p2 < nums.size(); p2++) {
      if (nums[p2] != val) {
        nums[p1] = nums[p2];
        p1++;
      }
    }
    
    return p1; // new length
  }
};
