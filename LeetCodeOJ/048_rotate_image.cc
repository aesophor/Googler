// Runtime: 4 ms, faster than 100.00% of C++ online submissions for Rotate Image.
// Memory Usage: 9.1 MB, less than 82.12% of C++ online submissions for Rotate Image.

class Solution {
public:
  void rotate(vector<vector<int>>& matrix) {
    transpose(matrix);
    
    // Reverse each row
    for (auto& row : matrix) {
      std::reverse(row.begin(), row.end());
    }
  }
  
private:
  void transpose(vector<vector<int>>& matrix) {
    for (int row = 0; row < matrix.size(); row++) {
      for (int col = row + 1; col < matrix.at(row).size(); col++) {
        // Swap (row,col) with (col,row)
        std::swap(matrix.at(row).at(col), matrix.at(col).at(row));
      }
    }
  }
};
