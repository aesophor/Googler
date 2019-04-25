// Runtime: 8 ms, faster than 99.32% of C++ online submissions for Two Sum II - Input array is sorted.
// Memory Usage: 9.5 MB, less than 79.67% of C++ online submissions for Two Sum II - Input array is sorted.

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int pfront = 0;
        int pback = numbers.size() - 1;
        
        while (pfront < pback) {
            int sum = numbers.at(pfront) + numbers.at(pback);
            
            if (sum < target) {
                pfront++;
            } else if (sum == target) {
                return {pfront + 1, pback + 1};
            } else {
                pback--;
            }
        }
        
        return {pfront + 1, pback + 1};
    }
};
