// Runtime: 32 ms, faster than 67.16% of C++ online submissions for Longest Palindromic Substring.
// Memory Usage: 9.2 MB, less than 96.25% of C++ online submissions for Longest Palindromic Substring.

class Solution {
public:
    string longestPalindrome(string s) {
        if (s.size() < 2) {
            return s;
        }
        
        int longest_pleft = 0;
        int max_len = 0;
        
        // Expand from center and exclude the first and the last char.
        for (int i = 0; i < s.size(); i++) {
            // 1. Center has one char
            int offset_from_center = checkOddPalindrome(s, i);
            int length = offset_from_center * 2 + 1;
            int pleft = i - offset_from_center;
            int pright = i + offset_from_center;
            
            if (isPalindrome(s, pleft, pright) && length > max_len) {
                longest_pleft = pleft;
                max_len = length;
            }
        }
        
        for (int i = 0; i < s.size() - 1; i++) {
            // 2. Center has two char
            int offset_from_centers = checkEvenPalindrome(s, i, i + 1);
            int length = offset_from_centers * 2 + 2; // two centers
            int pleft = i - offset_from_centers;
            int pright = (i + 1) + offset_from_centers;
            
            if (isPalindrome(s, pleft, pright) && length > max_len) {
                longest_pleft = pleft;
                max_len = length;
            }
        }
        
        return s.substr(longest_pleft, max_len);
    }
    
    bool isPalindrome(const string& s, int begin, int end) {
        while (begin < end) {
            if (s.at(begin) != s.at(end)) {
                return false;
            }
            begin++;
            end--;
        }
        return true;
    }
    
    /* Expand from center until expansion is impossible
     * @return offset from the center
     */
    int checkOddPalindrome(const string& s, int center) {
        int pleft = center - 1;
        int pright = center + 1;
        
        while (pleft >= 0 && pright < s.size() && s.at(pleft) == s.at(pright)) {
            pleft--;
            pright++;
        }
        // cabad
        // ^   ^  c != d
        return center - pleft - 1;
    }
    
    /* Expand from center1 and center2 until expansion is impossible
     * @return offset from center1 and center2
     */
    int checkEvenPalindrome(const string& s, int center1, int center2) {
        int pleft = center1 - 1;
        int pright = center2 + 1;
        
        while (pleft >= 0 && pright < s.size() && s.at(pleft) == s.at(pright)) {
            pleft--;
            pright++;
        }
        return center1 - pleft - 1;
    }
};
