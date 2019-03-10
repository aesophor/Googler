// Runtime: 4 ms, faster than 100.00% of C++ online submissions for To Lower Case.
// Memory Usage: 8.3 MB, less than 47.92% of C++ online submissions for To Lower Case.

class Solution {
public:
    string toLowerCase(string& str) {
        for (auto& c : str) {
            if (c >= 'A' && c <= 'Z') {
                c += 'a' - 'A';
            }
        }
        return str;
    }
};
