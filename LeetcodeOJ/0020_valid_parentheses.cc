// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Valid Parentheses.
// Memory Usage: 8.5 MB, less than 60.02% of C++ online submissions for Valid Parentheses.

class Solution {
 public:
  bool isValid(string s) {
    stack<char> st;
    
    for (auto c : s) {
      if (isOpeningParen(c)) {
        st.push(c);
      } else {
        char target = getOpeningParen(c);
        if (st.empty() || st.top() != target) {
          return false;
        } else {
          st.pop();
        }
      }
    }
    return st.empty();
  }
  
 private:
  bool isOpeningParen(char c) {
    return c == '(' || c == '[' || c == '{';
  }
  
  char getOpeningParen(char c) {
    switch (c) {
      case ')':
        return '(';
      case ']':
        return '[';
      case '}':
        return '{';
      default:
        return 0x00; // oh no
    }
  }
};
