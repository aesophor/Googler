// Runtime: 4 ms, faster than 80.37% of C++ online submissions for Add Binary.
// Memory Usage: 8.6 MB, less than 90.91% of C++ online submissions for Add Binary.

class Solution {
 public:
  string addBinary(string a, string b) {
    string result;
    std::reverse(a.begin(), a.end());
    std::reverse(b.begin(), b.end());
    
    bool carry = false;
    
    for (int i = 0; i < a.size() || i < b.size(); i++) {
      int sum = 0;
      
      if (i >= a.size()) { // a has no more digits
        sum = b[i] - '0';
      } else if (i >= b.size()) { // b has no more digits
        sum = a[i] - '0';
      } else {
        sum = (b[i] - '0') + (a[i] - '0');
      }
      
      if (carry) {
        sum += 1;
        carry = false;
      }
      
      result += (sum % 2) + '0';
      
      if (sum > 1) {
        carry = true;
      }
    }
    
    if (carry) {
      result += '1';
    }
    
    std::reverse(result.begin(), result.end());
    return result;
  }
};
