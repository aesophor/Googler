// Runtime: 16 ms, faster than 96.18% of C++ online submissions for Container With Most Water.
// Memory Usage: 9.8 MB, less than 68.04% of C++ online submissions for Container With Most Water.

class Solution {
 public:
  int maxArea(vector<int>& height) {
    int left = 0;
    int right = height.size() - 1;
    int max_area = 0;
    
    while (left < right) {
      int area = (right - left) * std::min(height[left], height[right]);
      max_area = std::max(max_area, area);
      
      if (height[left] < height[right]) {
        left++;
      } else {
        right--;
      }
    }
    
    return max_area;
  }
};
