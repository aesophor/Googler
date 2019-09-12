// Runtime: 4 ms, faster than 99.04% of C++ online submissions for Trapping Rain Water.
// Memory Usage: 9.3 MB, less than 51.17% of C++ online submissions for Trapping Rain Water.

class Solution {
 public:
  int trap(vector<int>& height) {
    vector<int> leftHighest(height.size(), 0);
    for (int i = 1; i < height.size(); i++) {
      leftHighest[i] = std::max(leftHighest[i - 1], height[i - 1]);
    }
    
    int area = 0;
    int rightHighest = 0;
    for (int i = height.size() - 1; i >= 0; i--) {
      if (leftHighest[i] > height[i] && height[i] < rightHighest) {
        area += std::min(leftHighest[i], rightHighest) - height[i];
      }
      rightHighest = std::max(rightHighest, height[i]);
    }
    return area;
  }
};
