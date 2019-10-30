// Runtime: 8 ms, faster than 93.73% of C++ online submissions for Search a 2D Matrix.
// Memory Usage: 9.6 MB, less than 100.00% of C++ online submissions for Search a 2D Matrix.

class Solution {
 public:
  bool searchMatrix(vector<vector<int>>& matrix, int target) {
    if (matrix.empty()) {
      return false;
    }
    
    int colSize = matrix.front().size();
    int rowSize = matrix.size();
    
    int i = 0;
    int j = rowSize - 1;
    
    while (i >= 0 && i < colSize && j >= 0 && j < rowSize) {
      int& num = matrix[j][i];
      if (num == target) {
        return true;
      } else if (num < target) {
        i++;
      } else { // num > target
        j--;
      }
    }
    
    return false;
  }
};
