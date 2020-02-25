// Runtime: 8 ms, faster than 99.44% of C++ online submissions for Evaluate Reverse Polish Notation.
// Memory Usage: 11.5 MB, less than 100.00% of C++ online submissions for Evaluate Reverse Polish Notation.

class Solution {
 public:
  int evalRPN(vector<string>& tokens) {
    std::stack<int> s;
    std::pair<int, int> operands;
    
    for (const auto& token : tokens) {
      if (token == "+") {
        operands = popTwo(s);
        s.push(operands.first + operands.second);
      } else if (token == "-") {
        operands = popTwo(s);
        s.push(operands.first - operands.second);       
      } else if (token == "*") {
        operands = popTwo(s);
        s.push(operands.first * operands.second);
      } else if (token == "/") {
        operands = popTwo(s);
        s.push(operands.first / operands.second);
      } else {
        s.push(std::stoi(token));
      }
    }
    
    return s.top();
  }
  
 private:
  inline std::pair<int, int> popTwo(std::stack<int>& s) {
    std::pair<int, int> ret;
    
    ret.second = s.top();
    s.pop();
    ret.first = s.top();
    s.pop();
    
    return ret;
  }
};
