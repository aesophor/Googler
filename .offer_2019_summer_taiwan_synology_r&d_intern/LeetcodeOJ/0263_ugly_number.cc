// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Ugly Number.
// Memory Usage: 8.1 MB, less than 47.72% of C++ online submissions for Ugly Number.

class Solution {
 public:
  bool isUgly(int num) {
    // 1, 2, 3, 4, 5, 6
    if (num <= 0) return false;
    else if (num == 1) return true;
    else if (num % 2 == 0) return isUgly(num / 2);
    else if (num % 3 == 0) return isUgly(num / 3);
    else if (num % 5 == 0) return isUgly(num / 5);
    else return false;
  }
};
