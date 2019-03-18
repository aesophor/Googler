// Runtime: 224 ms, faster than 8.99% of C++ online submissions for Sum of Square Numbers.
// Memory Usage: 61.2 MB, less than 8.20% of C++ online submissions for Sum of Square Numbers.

class Solution {
public:
    bool judgeSquareSum(int c) {
        unordered_set<int> complement;
        
        for (int i = 0; i <= std::sqrt(c); i++) {
            complement.insert(i * i);
            if (complement.find(c - i * i) != complement.end()) {
                return true;
            }
        }
        return false;
    }
};
