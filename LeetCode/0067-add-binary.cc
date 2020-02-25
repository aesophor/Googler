// Runtime: 4 ms, faster than 81.59% of C++ online submissions for Add Binary.
// Memory Usage: 8.7 MB, less than 69.09% of C++ online submissions for Add Binary.

class Solution {
 public:
  string addBinary(string a, string b) {
    bool carry = false;
    int p1 = a.size() - 1;
    int p2 = b.size() - 1;
    std::string result;
    
    while (p1 >= 0 || p2 >= 0 || carry) {
      int bit = 0;
      
      if (carry) {
        bit++;
        carry = false;
      }
      
      if (p1 >= 0) {
        bit += a[p1] - '0';  
      }
      
      if (p2 >= 0) {
        bit += b[p2] - '0';
      }
      
      if (bit >= 2) {
        bit -= 2;
        carry = true;
      }
      
      result += '0' + bit;
      
      p1--;
      p2--;
    }
    
    std::reverse(result.begin(), result.end());
    return result;
  }
};
