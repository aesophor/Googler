// Runtime: 12 ms, faster than 98.69% of C++ online submissions for Search a 2D Matrix.
// Memory Usage: 10.5 MB, less than 92.55% of C++ online submissions for Search a 2D Matrix.

class Solution {
public:
  bool searchMatrix(vector<vector<int>>& matrix, int target) {
    // Remove all invalid rows from the matrix.
    matrix.erase(std::remove_if(matrix.begin(), matrix.end(), [](vector<int>& row){
      return row.empty(); 
    }), matrix.end());
    
    if (matrix.empty()) {
      return false;
    }
    
    
    // Find the index of vector where `target` should be in.
    int left = 0;
    int right = matrix.size() - 1;
    while (left <= right) {
      int mid = left + (right - left) / 2;
      if (matrix.at(mid).front() < target) {
        left = mid + 1;
      } else if (matrix.at(mid).front() > target) {
        right = mid - 1;
      } else { // equals
        return true;
      }
    }
    
    // Calibrate binary search result lol
    if (left == matrix.size() || (matrix.at(left).front() > target && left > 0)) {
      left--;
    }
    
    // Perform binary search on the row :D
    vector<int>& row = matrix.at(left);
    left = 0;
    right = row.size() - 1;
    while (left <= right) {
      int mid = left + (right - left) / 2;
      if (row.at(mid) < target) {
        left = mid + 1;
      } else if (row.at(mid) > target) {
        right = mid - 1;
      } else { // equals
        return true;
      }
    }
    
    return false;
  }
};

// Experiment: perform binary search on 
// [1, 10, 23] to find 13
//  ^       ^
//  l       r

// (0 + 2) / 2 = 1   <- mid
// mid < 13, l = mid + 1, l = 2
