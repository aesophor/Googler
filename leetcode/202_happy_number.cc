// Runtime: 4 ms, faster than 100.00% of C++ online submissions for Happy Number.
// Memory Usage: 8 MB, less than 94.32% of C++ online submissions for Happy Number.

class Solution {
public:
    bool isHappy(int n) {
        int sum = 0;
        do {
            sum = 0;
            while (n != 0) {
                int digit = n % 10;
                sum += digit * digit;
                n /= 10;
            }
            n = sum;
            
            // There are only two happy numbers less than 10 (exclusive),
            // 1 and 7.
            if (n < 10 && n != 1 && n != 7) {
                return false;
            }
        } while (sum != 1);
        
        return true;
    }
};
