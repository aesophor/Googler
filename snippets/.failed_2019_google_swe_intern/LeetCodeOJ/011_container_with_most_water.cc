// Runtime: 20 ms, faster than 98.67% of C++ online submissions for Container With Most Water.
// Memory Usage: 10 MB, less than 80.25% of C++ online submissions for Container With Most Water.

class Solution {
public:
  int maxArea(vector<int>& height) {
    int left = 0;
    int right = height.size() - 1;
    int max_area = 0;
    
    while (left <= right) {
      int& left_height = height.at(left);
      int& right_height = height.at(right);
      max_area = std::max(max_area, std::min(left_height, right_height) * (right - left));
      
      if (left_height <= right_height) {
        left++;
      } else {
        right--;
      }
    }
    
    return max_area;
  }
};
