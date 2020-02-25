// Runtime: 12 ms, faster than 54.42% of C++ online submissions for Search a 2D Matrix.
// Memory Usage: 9.8 MB, less than 72.73% of C++ online submissions for Search a 2D Matrix.

class Solution {
 public:
  bool searchMatrix(vector<vector<int>>& matrix, int target) {
    if (matrix.empty()) {
      return false;
    }
    
    int height = matrix.size();
    int width = matrix[0].size();
    
    int row = height - 1;
    int col = 0;
    
    while (col >= 0 && col < width && row >= 0 && row < height) {
      const int& num = matrix[row][col];
      if (num == target) {
        return true;
      } else if (num < target) {
        col++;
      } else {  // num > target
        row--;
      }
    }
    
    return false;
  }
};
