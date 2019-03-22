// Runtime: 16 ms, faster than 49.94% of C++ online submissions for Find Common Characters.
// Memory Usage: 10 MB, less than 100.00% of C++ online submissions for Find Common Characters.

class Solution {
public:
  vector<string> commonChars(vector<string>& A) {
    // Sort each string alphabetically to perform binary search :D
    // also look for the string with minimum length.
    int min_str_idx = 0;
    int min_str_len = A.at(0).size();
    
    for (int i = 0; i < A.size(); i++) {
      string& s = A.at(i);
      std::sort(s.begin(), s.end());
      
      if (s.size() < min_str_len) {
        min_str_idx = i;
        min_str_len = s.size();
      }
    }
    
    
    vector<string> common_chars;
    
    // Iterate through the string with minimum length
    for (auto c : A.at(min_str_idx)) {
      bool is_common = false;
      
      // and perform binary search on the rest of the strings.
      for (int i = 0; i < A.size(); i++) {
        // but don't perform binary search on itself @_@
        if (i == min_str_idx) {
          continue;
        }
        
        is_common = false;
        string& s = A.at(i);
        
        int left = 0;
        int right = s.size() - 1;
        while (left <= right) {
          int mid = left + (right - left) / 2;
          if (s.at(mid) < c) {
            left = mid + 1;
          } else if (s.at(mid) > c) {
            right = mid - 1;
          } else { // equals
            is_common = true;
            s.erase(find(s.begin(), s.end(), c));
            break;
          }
        }
        
        // If this string doesn't contain this char,
        // we don't have to continue the search :O
        if (!is_common) {
          break;
        }
      }
      
      if (is_common) {
        common_chars.push_back(string(1, c));
      }
    }
    
    return common_chars;
  }
};

// b e l l a
// ^
// a e l l b
// a b e l l
// e o l l r

// check "label", "roller" for the character 'b'
// if all string has this character, add this char
// to the common vector.


/*
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
*/
