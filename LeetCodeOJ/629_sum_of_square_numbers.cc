// Runtime: 4 ms, faster than 100.00% of C++ online submissions for Sum of Square Numbers.
// Memory Usage: 8.6 MB, less than 96.72% of C++ online submissions for Sum of Square Numbers.

class Solution {
public:
    bool judgeSquareSum(int c) {
        int l = 0;
        int r = (int) std::sqrt(c);
        
        while (l <= r) {
            int sum = l * l;
            if (sum == c - r * r) {
                return true;
            } else if (sum < c - r * r) {
                l++;
            } else { // sum > c
                r--;
            }
        }
        return false;
    }
};
