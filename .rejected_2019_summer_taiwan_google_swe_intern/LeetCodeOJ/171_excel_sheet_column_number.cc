// Runtime: 4 ms, faster than 100.00% of C++ online submissions for Excel Sheet Column Number.
// Memory Usage: 8.2 MB, less than 31.29% of C++ online submissions for Excel Sheet Column Number.

class Solution {
public:
    int titleToNumber(string s) {
        int result = 0;
        for (auto c : s) {
            result *= 26;
            result += c - 0x40;
        }
        return result;
    }
};
