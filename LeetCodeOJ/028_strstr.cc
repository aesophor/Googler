// Runtime: 8 ms, faster than 98.91% of C++ online submissions for Implement strStr().
// Memory Usage: 9.4 MB, less than 73.01% of C++ online submissions for Implement strStr().

class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.empty()) {
            return 0;
        }
        
        if (haystack.size() < needle.size()) {
            return -1;
        }
        
        for (int i = 0; i < haystack.size(); i++) {
            if (i + needle.size() -1 > haystack.size() - 1) {
                break;
            }
            
            if (haystack.at(i) == needle.at(0)) {
                for (int j = 0; j < needle.size(); j++) {
                    if (haystack.at(i+j) != needle.at(j)) {
                        break;
                    } else if (j == needle.size()-1 && haystack.at(i+j) == needle.at(j)) {
                        return i;
                    }
                }
            }
        }
        
        return -1;
    }
};
