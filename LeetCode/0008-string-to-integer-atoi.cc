// Runtime: 4 ms, faster than 84.69% of C++ online submissions for String to Integer (atoi).
// Memory Usage: 8.5 MB, less than 67.16% of C++ online submissions for String to Integer (atoi).

class Solution {
 public:
  int myAtoi(string str) {
    bool is_negative = false;
    int result = 0;
    int ptr = 0;
    
    // Remove preceding whitespaces
    size_t pos = str.find_first_not_of(' ');
    if (pos == std::string::npos) {
      return 0;
    }
    str = str.substr(pos);
    
    if (str.front() != '+' && str.front() != '-' && !isDigit(str.front())) {
      return 0;
    }
    
    switch (str.front()) {
      case '-':
        is_negative = true;
        ptr = 1;
        break;
      case '+':
        ptr = 1;
        break;
      default:
        break;
    }
    
    for (; ptr < str.size() && isDigit(str[ptr]); ptr++) {
      if (result > INT_MAX / 10) {
        return (is_negative) ? INT_MIN : INT_MAX;
      }
      result *= 10;

      int next_digit = str[ptr] - '0';
      if (result > INT_MAX - next_digit) {
        return (is_negative) ? INT_MIN : INT_MAX;
      }
      result += next_digit;
    }
    
    return (is_negative) ? -result : result;
  }
  
 private:
  inline bool isDigit(const char c) {
    return c >= '0' && c <= '9';
  }
};
