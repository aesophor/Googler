// Runtime: 4 ms, faster than 58.66% of C++ online submissions for Valid Parentheses.
// Memory Usage: 8.5 MB, less than 74.42% of C++ online submissions for Valid Parentheses.

class Solution {
 public:
  bool isValid(string s) {
    std::stack<char> st;
    
    for (auto c : s) {
      if (isOpeningParen(c)) {
        st.push(getClosingParen(c));
      } else {
        if (st.empty() || st.top() != c) {
          return false;
        }
        st.pop();
      }
    }
    
    return st.empty();
  }
  
 private:
  bool isOpeningParen(char c) {
    return c == '(' || c == '[' || c == '{';
  }
  
  char getClosingParen(char c) {
    switch (c) {
      case '(':
        return ')';
      case '[':
        return ']';
      case '{':
        return '}';
      default:
        return 0x00; // should not get here
    }
  }
};
