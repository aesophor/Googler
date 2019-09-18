// Runtime: 4 ms, faster than 67.85% of C++ online submissions for Reverse Bits.
// Memory Usage: 8.1 MB, less than 95.83% of C++ online submissions for Reverse Bits.

class Solution {
 public:
  uint32_t reverseBits(uint32_t n) {
    int result = 0;
    
    for (int i = 0; i < 32; i++) {
      result |= (n & 1);
      if (i != 31) result <<= 1;
      n >>= 1;
    }
    
    return result;
  }
};
