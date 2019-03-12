// Runtime: 8 ms, faster than 98.78% of C++ online submissions for Longest Valid Parentheses.
// Memory Usage: 11 MB, less than 34.67% of C++ online submissions for Longest Valid Parentheses.

class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> st;
        
        for (int i = 0; i < s.size(); i++) {
            if (s.at(i) == '(') {
                st.push(i); // indices of valid (matched) parens will be popped
            } else { // ')'
                if (st.empty() || s.at(st.top()) == ')') {
                    st.push(i); // indices of invalid parens won't be poppped
                } else {
                    st.pop();
                }
            }
        }
        
        // Keypoint: string s is "segmentated" by INVALID parens,
        // we can calculate the length of valid substrings as if
        // we split the string by those invalid parens
        int max_len = 0;
        int cur_len = 0;
        
        for (int i = s.size() - 1; i >= 0; i--) {
            if (!st.empty() && st.top() == i) {
                max_len = std::max(max_len, cur_len);
                st.pop();
                cur_len = 0;
            } else {
                cur_len++;
            }
        }
        return std::max(max_len, cur_len);
    }
};
