// Runtime: 4 ms, faster than 95.96% of C++ online submissions for Trapping Rain Water.
// Memory Usage: 9.2 MB, less than 60.76% of C++ online submissions for Trapping Rain Water.

class Solution {
 public:
  int trap(vector<int>& height) {
    if (height.empty()) {
      return 0;
    }
    
    int left_highest[height.size()];
    left_highest[0] = 0;
   
    for (int i = 0; i < height.size() - 1; i++) {
      left_highest[i + 1] = std::max(left_highest[i], height[i]);
    }
   
    
    
    int right_highest = 0;
    int area = 0;
    
    for (int i = height.size() - 1; i >= 0; i--) {
      // 積水條件：本地高度必須低於左右兩側高度
      if (height[i] < left_highest[i] && height[i] < right_highest) {
        area += std::min(left_highest[i], right_highest) - height[i];
      }
      right_highest = std::max(right_highest, height[i]);
    }
    
    return area;
  }
};
