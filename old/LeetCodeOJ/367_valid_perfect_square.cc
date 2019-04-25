// Runtime: 4 ms, faster than 100.00% of C++ online submissions for Valid Perfect Square.
// Memory Usage: 8 MB, less than 77.91% of C++ online submissions for Valid Perfect Square.

class Solution {
public:
    bool isPerfectSquare(int num) {
        int l = 1;
        int r = num;
        
        while (l <= r) {
            int mid = l + (r - l) / 2;
            
            if (mid == (float) num / mid) {
                return true;
            } else if (mid < num / mid) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return false;
    }
};
