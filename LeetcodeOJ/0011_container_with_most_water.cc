// Runtime: 20 ms, faster than 89.87% of C++ online submissions for Container With Most Water.
// Memory Usage: 9.9 MB, less than 49.99% of C++ online submissions for Container With Most Water.

class Solution {
 public:
  int maxArea(vector<int>& height) {
    int lo = 0;
    int hi = height.size() - 1;
    
    int maxArea_ = 0;
    while (lo < hi) {
      maxArea_ = std::max(maxArea_, std::min(height[lo], height[hi]) * (hi - lo));
      
      if (height[lo] <= height[hi]) {
        lo++;
      } else if (height[lo] > height[hi]) {
        hi--;
      }
    }
    return maxArea_;
  }
};
