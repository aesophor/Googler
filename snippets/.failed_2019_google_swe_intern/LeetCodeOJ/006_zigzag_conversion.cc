// Runtime: 44 ms, faster than 23.51% of C++ online submissions for ZigZag Conversion.
// Memory Usage: 22.8 MB, less than 17.56% of C++ online submissions for ZigZag Conversion.

class Solution {
public:
    string convert(string s, int numRows) {
        // Pivot this shit from 0 ~ numRows - 1
        vector<vector<char>> zigzag(numRows);
        int i = 0;
        bool incrementing = true;
        
        for (auto c : s) {
            zigzag.at(i).push_back(c);
            
            if (numRows > 1) {
                if (incrementing) {
                    i++;
                } else {
                    i--;
                }
                
                if (i == numRows - 1) {
                    incrementing = false;
                } else if (i == 0) {
                    incrementing = true;
                }
            }
        }
        
        
        // Build the result string from the 2D vector
        string result;
        for (auto& row : zigzag) {
            for (auto c : row) {
                result += c;
            }
        }
        return result;
    }
};
