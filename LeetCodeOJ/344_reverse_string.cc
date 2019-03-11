// Runtime: 56 ms, faster than 98.01% of C++ online submissions for Reverse String.
// Memory Usage: 17.9 MB, less than 48.84% of C++ online submissions for Reverse String.

class Solution {
public:
    void reverseString(vector<char>& s) {
        int begin = 0;
        int end = s.size() - 1;
        
        while (begin < end) {
            swap(s.at(begin), s.at(end));
            begin++;
            end--;
        }
    }
    
    inline void swap(char& a, char& b) {
        char temp = a;
        a = b;
        b = temp;
    }
};
