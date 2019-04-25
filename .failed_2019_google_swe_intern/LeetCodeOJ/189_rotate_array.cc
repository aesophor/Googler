// Runtime: 16 ms, faster than 100.00% of C++ online submissions for Rotate Array.
// Memory Usage: 9.5 MB, less than 78.88% of C++ online submissions for Rotate Array.

// [1,2,3,4,5,6,7] and k = 3
// [5,6,7,1,2,3,4] is the result
// 先分別轉567,1234, 得[4,3,2,1,7,6,5]
// 再轉全部, 得[5,6,7,1,2,3,4] 即答案

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        if (nums.size() < 2) {
            return;
        }
        
        k %= nums.size();
        reverse(nums, nums.size() - k, nums.size() - 1);
        reverse(nums, 0, nums.size() - k - 1);
        reverse(nums, 0, nums.size() - 1);
    }
    
    void reverse(vector<int>& nums, int begin, int end) {
        while (begin < end) {
            swap(nums.at(begin), nums.at(end));
            begin++;
            end--;
        }
    }
    
    inline void swap(int& a, int& b) {
        int temp = a;
        a = b;
        b = temp;
    }
};

/*
if (k == 0) return;
k %= nums.size();
nums.insert(nums.begin(), nums.end() - k, nums.end());
nums.erase(nums.end() - k, nums.end());
*/
