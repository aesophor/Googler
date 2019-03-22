// Runtime: 16 ms, faster than 49.94% of C++ online submissions for Find Common Characters.
// Memory Usage: 10 MB, less than 100.00% of C++ online submissions for Find Common Characters.

class Solution {
public:
  vector<string> commonChars(vector<string>& A) {
    vector<string> commons;
    
    for (auto c : A.at(0)) {
      bool common = true;
      
      for (int i = 1; i < A.size(); i++) {
        string& s = A.at(i);
        if (!hasChar(s, c)) {
          common = false;
          break;
        } else {
          // Remove this character from the target string
          // to prevent repeated check.
          s.erase(find(s.begin(), s.end(), c));
        }
      }
      
      if (common) {
        string ch = "";
        ch += c;
        commons.push_back(ch);
      }
    }
    
    return commons;
  }
  
  inline bool hasChar(const string& s, char c) {
    return s.find(c) != s.npos;
  }
};

// b e l l a
// ^

// check "label", "roller" for the character 'b'
// if all string has this character, add this char
// to the common vector.
