// Runtime: 4 ms, faster than 100.00% of C++ online submissions for Ugly Number.
// Memory Usage: 8 MB, less than 52.14% of C++ online submissions for Ugly Number.

class Solution {
public:
    bool isUgly(int num) {
        // 1, 2, 3, 4, 5, 6, 8, 9, 10, 12, 15, … 
        // For example, 11 is not an ugly number,
        // since it contains not only 2, 3, and 5 as factors.
        while (num > 1) {
            if (num % 2 == 0) {
                num /= 2;
            } else if (num % 3 == 0) {
                num /= 3;
            } else if (num % 5 == 0) {
                num /= 5;
            } else {
                return false;
            }
        }
        return num == 1;
    }
};
