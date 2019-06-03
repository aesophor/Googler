// Runtime: 68 ms, faster than 79.78% of C++ online submissions for Search a 2D Matrix II.
// Memory Usage: 12.9 MB, less than 60.69% of C++ online submissions for Search a 2D Matrix II.

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
      if (matrix[row][col] == target) {
        return true;
      } else if (matrix[row][col] > target) {
        row--;
      } else {
        col++;
      }
    }
    return false;
  }
};
