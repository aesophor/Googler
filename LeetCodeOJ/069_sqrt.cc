// Runtime: 12 ms, faster than 98.96% of C++ online submissions for Sqrt(x).
// Memory Usage: 13.9 MB, less than 53.54% of C++ online submissions for Sqrt(x).

class Solution {
public:
    int mySqrt(int x) {
        int l = 1;
        int r = x;
        
        while (l <= r) {
            int mid = l + (r - l) / 2;
            
            // 2 == 5 / 2  --> for 5, we want to get 2
            if (mid == x / mid) {
                return mid;
            } else if (mid < x / mid) {
                l = mid + 1;
            } else { // mid_pow > x
                r = mid - 1;
            }
        }
        return l - 1;
    }
};

// [1 2 3 4]
//    ^
