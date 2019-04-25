// Runtime: 120 ms, faster than 71.43% of C++ online submissions for Palindrome Number.
// Memory Usage: 73.2 MB, less than 19.84% of C++ online submissions for Palindrome Number.

class Solution {
public:
    bool isPalindrome(int x) {
        string s1 = std::to_string(x);
        string s2 = s1;
        std::reverse(s2.begin(), s2.end());
        return s1 == s2;
    }
};
