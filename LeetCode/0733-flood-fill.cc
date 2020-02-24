// Runtime: 20 ms, faster than 97.52% of C++ online submissions for Flood Fill.
// Memory Usage: 10.3 MB, less than 77.78% of C++ online submissions for Flood Fill.

class Solution {
 public:
  using image_t = vector<vector<int>>;
  
  image_t floodFill(image_t& image, int sr, int sc, int newColor) {
    size_t width = image[0].size();
    size_t height = image.size();
    int oldColor = image[sr][sc];

    if (sr >= height || sc >= width || oldColor == newColor) {
      return image;
    }
    
    
    std::queue<pair<int, int>> q;
    q.push({sr, sc});
    
    while (!q.empty()) {
      auto pos = q.front();
      q.pop();
      
      const int& r = pos.first;
      const int& c = pos.second;
      image[r][c] = newColor;
      
      if (r - 1 >= 0 && image[r - 1][c] == oldColor) q.push({r - 1, c});
      if (c - 1 >= 0 && image[r][c - 1] == oldColor) q.push({r, c - 1});
      if (r + 1 < height && image[r + 1][c] == oldColor) q.push({r + 1, c});
      if (c + 1 < width && image[r][c + 1] == oldColor) q.push({r, c + 1});
    }
    
    return image;
  }
};
