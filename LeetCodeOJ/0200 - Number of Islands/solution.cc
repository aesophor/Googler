// Runtime: 16 ms, faster than 59.11% of C++ online submissions for Number of Islands.
// Memory Usage: 12.3 MB, less than 12.36% of C++ online submissions for Number of Islands.

class Solution {
 public:
  int numIslands(vector<vector<char>>& grid) {
    if (grid.empty()) {
      return 0;
    }
    
    int rowSize = grid.size();
    int colSize = grid.front().size();
    
    
    // Grid BFS: search all islands
    int numIsland = 0;
    
    for (int i = 0; i < grid.size(); i++) {
      for (int j = 0; j < grid[i].size(); j++) {
        if (grid[i][j] == '0') {
          continue;
        }
        
        numIsland++;
        std::queue<std::pair<int, int>> q;
        q.push({i, j});

        while (!q.empty()) {
          int row = q.front().first;
          int col = q.front().second;
          char& c = grid[row][col];
          q.pop();

          if (c == '0') {
            continue;
          }

          c = '0'; // change this shit to water
          if (row - 1 >= 0) q.push({row - 1, col});
          if (col - 1 >= 0) q.push({row, col - 1});
          if (row + 1 <= rowSize - 1) q.push({row + 1, col});
          if (col + 1 <= colSize - 1) q.push({row, col + 1});
        }     
      }
    }
      
    return numIsland;
  }
};
