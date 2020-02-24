// Runtime: 4 ms, faster than 70.01% of C++ online submissions for Reverse Bits.
// Memory Usage: 8.1 MB, less than 87.50% of C++ online submissions for Reverse Bits.

class Solution {
 public:
  uint32_t reverseBits(uint32_t n) {
    uint32_t result = 0;
    
    for (int i = 0; i < 32; i++) {
      result <<= 1;
      result += n % 2;
      n >>= 1;
    }
    
    return result;
  }
};
