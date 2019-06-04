// Runtime: 4 ms, faster than 91.39% of C++ online submissions for Plus One.
// Memory Usage: 8.7 MB, less than 7.31% of C++ online submissions for Plus One.

class Solution {
 public:
  vector<int> plusOne(vector<int>& digits) {
    digits.back()++;
    
    for (int i = digits.size() - 1; i >= 0; i--) {
      if (digits[i] >= 10) {
        digits[i] -= 10;
        if (i - 1 < 0) {
          digits.insert(digits.begin(), 1);
        } else {
          digits[i - 1] += 1;
        }
      }
    }
    return digits;
  }
};
