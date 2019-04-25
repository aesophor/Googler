// Runtime: 8 ms, faster than 49.87% of C++ online submissions for Power of Two.
// Memory Usage: 7.9 MB, less than 98.72% of C++ online submissions for Power of Two.

class Solution {
public:
  bool isPowerOfTwo(int n) {
    bool last = 0;
    while (n != 0) {
      // Only the msb is allowed to be 1.
      if (last != 0) {
        return false;
      }
      last = n & 0x01;
      n = n >> 1;
      cout << n << endl;
    }
    return last == 1;
  }
};

// 0  00000
// 1  00001
// 2  00010
// 4  00100
// 8  01000
// 16 10000
