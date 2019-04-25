// Runtime: 4 ms, faster than 100.00% of C++ online submissions for Excel Sheet Column Title.
// Memory Usage: 8.2 MB, less than 26.17% of C++ online submissions for Excel Sheet Column Title.

class Solution {
public:
    string convertToTitle(int n) {
        // 進制轉換 (10轉26)，0 對 0x41, n必須先扣1
        string result;
        while (n != 0) {
            result = (char) (--n % 26 + 0x41) + result;
            n /= 26;
        }
        return result;
    }
};
