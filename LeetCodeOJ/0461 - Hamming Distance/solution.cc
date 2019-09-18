// Runtime: 4 ms, faster than 56.33% of C++ online submissions for Hamming Distance.
// Memory Usage: 8.3 MB, less than 54.54% of C++ online submissions for Hamming Distance.

class Solution {
 public:
  int hammingDistance(int x, int y) {
    int dist = 0;
    
    for (int i = 0; i < 32; i++) {
      if ((x & 1) != (y & 1)) {
        dist++;
      }
      x >>= 1;
      y >>= 1;
    }
    
    return dist;
  }
};
