// Runtime: 12 ms, faster than 87.01% of C++ online submissions for Search a 2D Matrix.
// Memory Usage: 10 MB, less than 51.94% of C++ online submissions for Search a 2D Matrix.

class Solution {
 public:
  bool searchMatrix(vector<vector<int>>& matrix, int target) {
    if (matrix.size() == 0) {
      return false;
    }
    
    int rowSize = matrix.size();
    int colSize = matrix[0].size();
    
    int row = rowSize - 1;
    int col = 0;
    
    while (row >= 0 && row < rowSize && col >= 0 && col < colSize) {
      if (matrix[row][col] > target) {
        row--;
      } else if (matrix[row][col] < target) {
        col++;
      } else {
        return true; // ==
      }
    }
    return false;
  }
};
