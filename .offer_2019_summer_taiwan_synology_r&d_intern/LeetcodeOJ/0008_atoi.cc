// Runtime: 4 ms, faster than 96.19% of C++ online submissions for String to Integer (atoi).
// Memory Usage: 8.4 MB, less than 73.04% of C++ online submissions for String to Integer (atoi).

class Solution {
 public:
  int myAtoi(string str) {
    int firstPos = 0;
    while (str[firstPos] == ' ') {
      firstPos++;
    }
    
    if (str[firstPos] != '+' && str[firstPos] != '-' && !isNumeric(str[firstPos])) {
      return 0;
    }
    
    bool negative = false;
    if (str[firstPos] == '+' || str[firstPos] == '-') {
      negative = str[firstPos] == '-';
      firstPos++;
    }
    
    int result = 0;
    for (int i = firstPos; i < str.size() && isNumeric(str[i]); i++) {
      int nextDigit = str[i] - '0';
      if (result > (INT_MAX - nextDigit) / 10) {
        return (negative) ? INT_MIN : INT_MAX;
      }
      result *= 10;
      result += nextDigit;
    }
    
    return (negative) ? -result : result;
  }
  
 private:
  inline bool isNumeric(char c) {
    return c >= '0' && c <= '9';
  }
};
