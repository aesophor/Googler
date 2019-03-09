// Runtime: 4 ms, faster than 100.00% of C++ online submissions for Valid Parentheses.
// Memory Usage: 9 MB, less than 35.34% of C++ online submissions for Valid Parentheses.

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for (auto c : s) {
            if (isOpeningParentheses(c)) {
                st.push(getClosingParentheses(c));
            } else {
                if (!st.empty() && c == st.top()) {
                    st.pop();
                } else {
                    return false;
                }
            }
        }
        
        return st.empty();
    }
    
    inline bool isOpeningParentheses(char c) {
        return c == '(' || c == '[' || c == '{';
    }
    
    inline char getClosingParentheses(char c) {
        switch (c) {
            case '(':
                return ')';
            case '[':
                return ']';
            case '{':
                return '}';
            default:
                return 0x00;
        }
    }
};
