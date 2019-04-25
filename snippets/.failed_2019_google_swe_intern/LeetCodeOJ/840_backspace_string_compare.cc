// Runtime: 4 ms, faster than 100.00% of C++ online submissions for Backspace String Compare.
// Memory Usage: 9.2 MB, less than 26.74% of C++ online submissions for Backspace String Compare.

class Solution {
public:
    bool backspaceCompare(string S, string T) {
        stack<char> s1;
        stack<char> s2;
        return processString(s1, S) == processString(s2, T);
    }
    
    inline stack<char>& processString(stack<char>& st, const string& str) {
        static const char kBackspace = '#';
        
        for (auto c : str) {
            if (c == kBackspace) {
                if (!st.empty()) {
                    st.pop();
                }
            } else {
                st.push(c);
            }
        }
        
        return st;
    }
};
