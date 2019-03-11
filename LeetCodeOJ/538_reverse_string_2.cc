// Runtime: 8 ms, faster than 99.18% of C++ online submissions for Reverse String II.
// Memory Usage: 9.9 MB, less than 28.57% of C++ online submissions for Reverse String II.

class Solution {
public:
    string reverseStr(string s, int k) {
        int begin = 0;
        int end = 0;
        
        for (int i = 0; i < s.size(); i += 2 * k) {
            begin = i;
            end = i + k - 1;
            end = (end > s.size() - 1) ? s.size() - 1 : end;
            
            while (begin < end) {
                swap(s.at(begin), s.at(end));
                begin++;
                end--;
            }
        }
        
        return s;
    }
    
    inline void swap(char& a, char& b) {
        char temp = a;
        a = b;
        b = temp;
    }
};
