// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Plus One.
// Memory Usage: 8.4 MB, less than 100.00% of C++ online submissions for Plus One.

class Solution {
 public:
  vector<int> plusOne(vector<int>& digits) {
    bool carry = false;
    
    for (int i = digits.size() - 1; i >= 0; i--) {
      if (i == digits.size() - 1) {
        digits[i] += 1;   
      }
      
      if (carry) {
        digits[i] += 1;
        carry = false;
      }
      
      if (digits[i] >= 10) {
        digits[i] %= 10;
        carry = true;
      }
    }
    
    if (carry) {
      digits.insert(digits.begin(), 1);
    }
    
    return digits;
  }
};
