// Runtime: 4 ms, faster than 100.00% of C++ online submissions for First Bad Version.
// Memory Usage: 8.2 MB, less than 31.89% of C++ online submissions for First Bad Version.

// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int l = 1;
        int r = n;
        
        while (l <= r) {
            // int mid = (l + r) / 2;
            int mid = l + (r - l) / 2;
            if (isBadVersion(mid)) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return l;
    }
};

//  1 2 3 4 5 6 7 8 9
//  G G G G G B B B B
//          ^
//         mid
