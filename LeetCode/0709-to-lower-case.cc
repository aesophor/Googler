// Runtime: 4 ms, faster than 51.70% of C++ online submissions for To Lower Case.
// Memory Usage: 8.3 MB, less than 58.97% of C++ online submissions for To Lower Case.

class Solution {
 public:
  string toLowerCase(string str) {
    for (auto& c : str) {
      if (c >= 'A' && c <= 'Z') {
        c += 'a' - 'A';
      }
    }
    return str;
  }
};
