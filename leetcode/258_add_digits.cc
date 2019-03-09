// Runtime: 4 ms, faster than 100.00% of C++ online submissions for Add Digits.
// Memory Usage: 8.1 MB, less than 71.90% of C++ online submissions for Add Digits.

// With recursion
class Solution {
public:
    int addDigits(int num) {
        if (num < 10) {
            return num;
        }
        
        int sum = 0;
        while (num != 0) {
            sum += num % 10;
            num /= 10;
        }
        
        return addDigits(sum);
    }
};

// Without recursion
class Solution {
public:
    int addDigits(int num) {
        int sum = 0;
        do {
            sum = 0;
            while (num != 0) {
                sum += num % 10;
                num /= 10;
            }
            num = sum;
        } while (sum > 9);

        return sum;
    }
};
