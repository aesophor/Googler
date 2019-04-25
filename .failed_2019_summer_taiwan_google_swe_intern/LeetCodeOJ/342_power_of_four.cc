// Runtime: 8 ms, faster than 48.55% of C++ online submissions for Power of Four.
// Memory Usage: 8 MB, less than 73.94% of C++ online submissions for Power of Four.

class Solution {
public:
  bool isPowerOfFour(int num) {
    int count = 0;
    
    bool last = 0;
    while (num != 0) {
      if (last != 0) {
        return false;
      }
      last = num & 0x01;
      num >>= 1;
      count++;
    }
    
    return count % 2 != 0;
  }
};

// 1  00001
// 4  00100
// 16 10000
// 64
