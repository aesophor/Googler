// Runtime: 16 ms, faster than 94.69% of C++ online submissions for Evaluate Reverse Polish Notation.
// Memory Usage: 11.4 MB, less than 83.17% of C++ online submissions for Evaluate Reverse Polish Notation.

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        
        for (auto& token : tokens) {
            if (isOperator(token)) {
                int op2 = st.top();
                st.pop();
                int op1 = st.top();
                st.pop();
                
                switch (token.at(0)) {
                    case '+':
                        st.push(op1 + op2);
                        break;
                    case '-':
                        st.push(op1 - op2);
                        break;
                    case '*':
                        st.push(op1 * op2);
                        break;
                    case '/':
                        st.push(op1 / op2);
                        break;
                    default:
                        break;
                }
            } else {
                st.push(std::stoi(token));
            }
        }
        
        return st.top();
    }
    
    inline bool isOperator(const string& s) {
        return s == "+" || s == "-" || s == "*" || s == "/";
    }
};
