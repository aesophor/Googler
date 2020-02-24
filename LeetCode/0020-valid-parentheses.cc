// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Valid Parentheses.
// Memory Usage: 8.5 MB, less than 78.29% of C++ online submissions for Valid Parentheses.

class Solution {
 public:
  bool isValid(string str) {
    std::stack<char> s;

    for (const auto c : str) {
      if (isOpeningParen(c)) {
        s.push(getClosingParen(c));
      } else if (s.empty() || s.top() != c) {
        return false;
      } else {
        s.pop();
      }
    }
    
    return s.empty();
  }
  
 private:
  bool isOpeningParen(const char c) {
    return c == '(' || c == '[' || c == '{';
  }
  
  char getClosingParen(const char c) {
    switch (c) {
      case '(':
        return ')';
      case '[':
        return ']';
      case '{':
        return '}';
      default:
        return 0x00;  // should not get here
    }
  }
};
