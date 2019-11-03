// Runtime: 44 ms, faster than 10.77% of C++ online submissions for Surrounded Regions.
// Memory Usage: 20.3 MB, less than 6.25% of C++ online submissions for Surrounded Regions.

class Solution {
 public:
  void solve(vector<vector<char>>& board) {
    if (board.empty() || board.size() < 3) {
      return;
    }
    
    int rowSize = board.size();
    int colSize = board.front().size();
    
    for (int i = 0; i < rowSize; i++) {
      for (int j = 0; j < colSize; j++) {
        // Skip borders
        if (i == 0 || i == rowSize - 1 || j == 0 || j == colSize - 1 || board[i][j] == 'X') {
          continue;
        }
        
        bool reachedBorder = false;
        std::vector<char*> flipped;
        
        std::queue<std::pair<int, int>> q;
        q.push({i, j});
        
        while (!q.empty()) {
          int row = q.front().first;
          int col = q.front().second;
          q.pop();
          
          if (board[row][col] == 'X') {
            continue;
          }
          
          board[row][col] = 'X';
          flipped.push_back(&board[row][col]);
          
          if (row - 1 >= 0) q.push({row - 1, col}); else reachedBorder = true;
          if (col - 1 >= 0) q.push({row, col - 1}); else reachedBorder = true;
          if (row + 1 <= rowSize - 1) q.push({row + 1, col}); else reachedBorder = true;
          if (col + 1 <= colSize - 1) q.push({row, col + 1}); else reachedBorder = true;
          
          if (reachedBorder) break;
        }
        
        if (reachedBorder) {
          for (auto p : flipped) {
            *p = 'O';
          }
        }

      }
    }
  }
};
