// Runtime: 40 ms, faster than 99.65% of C++ online submissions for Product of Array Except Self.
// Memory Usage: 12.5 MB, less than 81.84% of C++ online submissions for Product of Array Except Self.

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        // O(n) * 2 = O(n)
        int size = nums.size();
        vector<int> result(nums.size());
        result.at(0) = 1;
        
        // First pass: left -> right
        for (int i = 1; i < size; i++) {
            result.at(i) = result.at(i - 1) * nums.at(i - 1);
        }
        
        // Second pass: left <- right
        int right_product = 1;
        for (int i = size - 1; i >= 0; i--) {
            result.at(i) *= right_product;
            right_product *= nums.at(i);
        }
        
        return result;
    }
};

/*
bruteforce

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int pfront = 0;
        int pback = nums.size() - 1;
        
        vector<int> result;
        for (int i = 0; i < nums.size(); i++) {
            int product = 1;
            while (pfront <= pback) {
                if (pfront == i) {
                    pfront++;
                } else if (pback == i) {
                    pback--;
                } else {
                    if (pfront == pback) {
                        product *= nums.at(pfront);
                    } else {
                        product *= nums.at(pfront);
                        product *= nums.at(pback);    
                    }
                    pfront++;
                    pback--;
                }
            }
            result.push_back(product);
            pfront = 0;
            pback = nums.size() - 1;
        }
        return result;
    }
};
*/
