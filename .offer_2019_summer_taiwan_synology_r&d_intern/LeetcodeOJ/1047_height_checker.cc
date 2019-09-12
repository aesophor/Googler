// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Height Checker.
// Memory Usage: 8.6 MB, less than 100.00% of C++ online submissions for Height Checker.

class Solution {
 public:
  int heightChecker(vector<int>& heights) {
    int result = 0;
    vector<int> correctHeights = heights;
    std::sort(correctHeights.begin(), correctHeights.end());
    for (int i = 0; i < heights.size(); i++) {
      if (heights[i] != correctHeights[i]) {
        result++;
      }
    }
    return result;
  }
};
