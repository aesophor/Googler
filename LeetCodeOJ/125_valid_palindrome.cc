// Runtime: 12 ms, faster than 82.35% of C++ online submissions for Valid Palindrome.
// Memory Usage: 9.2 MB, less than 49.18% of C++ online submissions for Valid Palindrome.

class Solution {
public:
    bool isPalindrome(string s) {
        toLower(s);
        int pfront = 0;
        int pback = s.size() - 1;
        
        while (pfront < pback) {
            if (!isAlphanumeric(s.at(pfront))) {
                pfront++;
            } else if (!isAlphanumeric(s.at(pback))) {
                pback--;
            } else {
                if (s.at(pfront) != s.at(pback)) {
                    return false;
                }
                pfront++;
                pback--;
            }
        }
        
        return true;
    }
    
    string& toLower(string& s) {
        for (auto& c : s) {
            if (c >= 'A' && c <= 'Z') {
                c += 'a' - 'A';
            }
        }
        return s;
    }
    
    bool isAlphanumeric(char c) {
        return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || (c >= '0' && c <= '9');
    }
};
