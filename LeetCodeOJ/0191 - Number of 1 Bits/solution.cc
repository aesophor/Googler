// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Number of 1 Bits.
// Memory Usage: 8.1 MB, less than 95.12% of C++ online submissions for Number of 1 Bits.

class Solution {
 public:
  int hammingWeight(uint32_t n) {
    int weight = 0;
    
    for (int i = 0; i < 32; i++) {
      if (n & 1) {
        weight++;
      }
      n >>= 1;
    }
    
    return weight;
  }
};
