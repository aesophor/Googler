// Runtime: 4 ms, faster than 100.00% of C++ online submissions for Count and Say.
// Memory Usage: 9.2 MB, less than 33.03% of C++ online submissions for Count and Say.

class Solution {
public:
    string countAndSay(int n) {
        if (n == 1) {
            return "1";
        }
        
        string last = countAndSay(n - 1);
        string result;
        char current = last.at(0);
        int count[10] = { 0 };
        for (int i = 0; i < last.size(); i++) {
            // Same as the last appeared digit
            if (last.at(i) == current) {
                // Keep counting
                count[last.at(i) - 0x30]++;
            } else {
                // Update result string and reset counter
                result += std::to_string(count[current - 0x30]) + current;
                count[current -0x30] = 0;
                count[last.at(i) - 0x30] = 1;
                current = last.at(i);
            }
            
            if (i == last.size() - 1) {
                result += std::to_string(count[current- 0x30]) + current;
            }
        }
        
        return result;
    }
};
