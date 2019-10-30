// Runtime: 4 ms, faster than 84.20% of C++ online submissions for String to Integer (atoi).
// Memory Usage: 8.4 MB, less than 83.58% of C++ online submissions for String to Integer (atoi).

class Solution {
 public:
  int myAtoi(string str) {
    bool foundFirstValidChar = false;
    bool negative = false;
    int result = 0;
    
    for (auto c : str) {
      if (!foundFirstValidChar) {
        if (c == ' ') {
          continue;
        } else if (c == '+' || c == '-') {
          if (c == '-') negative = true;
          foundFirstValidChar = true;
          continue;
        } else if (c >= '0' && c <= '9') {
          foundFirstValidChar = true;
        } else {
          return 0;
        }
      }
      
      if (c >= '0' && c <= '9') {
        if (result < INT_MIN / 10) {
          return INT_MIN;
        }
        if (result > INT_MAX / 10) {
          return INT_MAX;
        }
        result *= 10;
        
        if (result > INT_MAX - (c - '0')) {
          return INT_MAX;
        }
        if (result < INT_MIN + (c - '0')) {
          return INT_MIN;
        }
        result += (negative) ? -(c - '0') : (c - '0');
      } else {
        break;
      }
    }
    
    return result;
  }
};
