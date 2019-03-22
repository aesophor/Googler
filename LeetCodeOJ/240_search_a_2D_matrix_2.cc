// Runtime: 72 ms, faster than 67.12% of C++ online submissions for Search a 2D Matrix II.
// Memory Usage: 12.9 MB, less than 49.43% of C++ online submissions for Search a 2D Matrix II.

class Solution {
public:
  bool searchMatrix(vector<vector<int>>& matrix, int target) {
    if (matrix.empty()) {
      return false;
    }
    
    int row = matrix.size() - 1;
    int col = 0;
    const int kColSize = matrix.at(0).size();
    
    while (row >= 0 && col < kColSize) {
      if (target < matrix[row][col]) {
        row--;
      } else if (target > matrix[row][col]) {
        col++;
      } else { // equals
        return true;
      }
    }
    
    return false;
  }
};
