// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Hamming Distance.
// Memory Usage: 8.2 MB, less than 77.27% of C++ online submissions for Hamming Distance.

class Solution {
 public:
  int hammingDistance(int x, int y) {
    int dist = 0;
    
    for (int i = 0; i < 32; i++) {
      dist += static_cast<int>(x % 2 != y % 2);
      x >>= 1;
      y >>= 1;
    }
    
    return dist;
  }
};
