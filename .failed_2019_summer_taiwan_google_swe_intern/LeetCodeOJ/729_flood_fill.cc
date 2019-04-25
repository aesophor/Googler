// Runtime: 28 ms, faster than 99.38% of C++ online submissions for Flood Fill.
// Memory Usage: 11.7 MB, less than 98.44% of C++ online submissions for Flood Fill.

// DFS
class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int new_color) {
        if (image[sr][sc] == new_color) {
            return image;
        }
        
        old_color_ = image[sr][sc];
        fill(image, sr, sc, new_color);
        return image;
    }
    
private:
    void fill(vector<vector<int>>& image, int sr, int sc, int new_color) {
        if (sr < 0 || sc < 0 || sr >= image.size() || sc >= image[sr].size()
           || image[sr][sc] != old_color_) {
            return;
        }
        
        image[sr][sc] = new_color;
        fill(image, sr, sc - 1, new_color); // left
        fill(image, sr, sc + 1, new_color); // right
        fill(image, sr - 1, sc, new_color); // down
        fill(image, sr + 1, sc, new_color); // up
    }
    
    int old_color_ = 0;
};


// DFS
class Solution {
public:
  vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int new_color) {
    if (image.empty() || image[sr][sc] == new_color) {
      return image;
    }
    
    // BFS Flood fill @_@
    int old_color = image[sr][sc];
    queue<pair<int, int>> q;
    q.push({sr, sc});
    
    while (!q.empty()) {
      pair<int, int> coord = q.front();
      q.pop();
      
      int& r = coord.first;
      int& c = coord.second;
      
      image[r][c] = new_color;
      
      if (r > 0 && image[r - 1][c] == old_color) {
        q.push({r - 1, c});
      }
      if (c > 0 && image[r][c - 1] == old_color) {
        q.push({r, c - 1});
      }
      if (r < image.size() - 1 && image[r + 1][c] == old_color) {
        q.push({r + 1, c});
      }
      if (c < image[0].size() - 1 && image[r][c + 1] == old_color) {
        q.push({r, c + 1});
      }
    }
    
    return image;
  }
};
