// Runtime: 16 ms, faster than 100.00% of C++ online submissions for Rotate Array.
// Memory Usage: 9.5 MB, less than 78.88% of C++ online submissions for Rotate Array.

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
