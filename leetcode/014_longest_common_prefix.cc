// Runtime: 8 ms, faster than 99.43% of C++ online submissions for Longest Common Prefix.
// Memory Usage: 9.5 MB, less than 74.41% of C++ online submissions for Longest Common Prefix.

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) {
            return "";
        }
        
        string common_prefix;
        
        for (int i = 0; i < getMinimumStringLength(strs); i++) {
            char c = strs.at(0).at(i);
            for (int j = 1; j < strs.size(); j++) {
                if (strs.at(j).at(i) != c) {
                    return common_prefix;
                }
            }
            common_prefix += c;
        }
        
        return common_prefix;
    }
    
    int getMinimumStringLength(const vector<string>& strs) {
        int min_length = strs.at(0).size();
        for (int i = 1; i < strs.size(); i++) {
            if (strs[i].size() < min_length) {
                min_length = strs[i].size();
            }
        }
        return min_length;
    }
};
