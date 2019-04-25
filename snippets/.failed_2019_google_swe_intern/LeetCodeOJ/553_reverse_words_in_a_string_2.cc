// Runtime: 24 ms, faster than 79.01% of C++ online submissions for Reverse Words in a String III.
// Memory Usage: 12 MB, less than 47.66% of C++ online submissions for Reverse Words in a String III.

class Solution {
public:
    string reverseWords(string s) {
        int begin = 0;
        int end = 0;
        
        while (begin < s.size()) {
            if (s.at(end) == ' ') { 
                reverse(s, begin, end - 1);
                begin = end + 1;
            } else if (end == s.size() - 1) { // or end of string
                reverse(s, begin, end);
                begin = end + 1;
            }
            end++;
        }
        
        return s;
    }
    
    inline void reverse(string& s, int begin, int end) {
        while (begin < end) {
            char temp = s.at(begin);
            s.at(begin) = s.at(end);
            s.at(end) = temp;
            begin++;
            end--;
        }
    }
};
