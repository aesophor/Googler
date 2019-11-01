// Runtime: 24 ms, faster than 76.97% of C++ online submissions for Flood Fill.
// Memory Usage: 10.4 MB, less than 66.67% of C++ online submissions for Flood Fill.

class Solution {
 public:
  vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
    if (image[sr][sc] == newColor) {
      return image;
    }
    
    int rowSize = image.size();
    int colSize = image.front().size();
    int oldColor = image[sr][sc];
    
    std::queue<std::pair<int, int>> q; // a queue of coordinates
    q.push({sr, sc});
    
    while (!q.empty()) {
      int row = q.front().first;
      int col = q.front().second;
      q.pop();
      
      if (image[row][col] != oldColor) {
        continue;
      }
      
      // Re-color this pixel.
      image[row][col] = newColor;
      
      // Push adjacent pixels onto the queue (if feasible)
      if (row - 1 >= 0) { q.push({row - 1, col}); }
      if (col - 1 >= 0) { q.push({row, col - 1}); }
      if (row + 1 <= rowSize - 1) { q.push({row + 1, col}); }
      if (col + 1 <= colSize - 1) { q.push({row, col + 1}); }
    }
    
    return image;
  }
};
