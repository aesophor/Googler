// Runtime: 12 ms, faster than 100.00% of C++ online submissions for Permutations.
// Memory Usage: 9.2 MB, less than 91.50% of C++ online submissions for Permutations.

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        int permutation_count = 1;
        for (int i = nums.size(); i >= 2; i--) {
            permutation_count *= i;
        }
        
        vector<vector<int>> permutations;
        permutations.push_back(nums);
        
        for (int i = 0; i < permutation_count - 1; i++) {
            nextPermutation(nums);
            permutations.push_back(nums);
        }
        
        return permutations;
    }
    
    void nextPermutation(vector<int>& nums) {
        if (nums.size() == 1) {
            return;
        } else if (nums.size() == 2) {
            swap(nums.at(0), nums.at(1));
            return;
        }
        
        int j = -1;
        
        // 1. Choose the right-most pair aj, aj+1 where aj < aj+1
        for (int i = nums.size() - 1; i >= 1; i--) {
            if (nums.at(i - 1) < nums.at(i)) {
                j = i - 1;
                break;
            }
        }
        
        // If there's no next permutation, sort the array in ascending order
        if (j == -1) {
            insertionSort(nums, 0, nums.size());
            return;
        }
        
        
        // 2. Choose the least items to the right of aj greater than aj
        int x = j + 1;
        for (int i = j + 1; i < nums.size(); i++) {
            if (nums.at(i) > nums.at(j) && nums.at(i) < nums.at(x)) {
                x = i;
            }
        }
        
        // 3. Swap this item and aj
        swap(nums.at(x), nums.at(j));
        
        // 4. Sort the remaining (to the right) items in ascending order
        insertionSort(nums, j + 1, nums.size());
    }
    
    void swap(int& a, int& b) {
        int temp = a;
        a = b;
        b = temp;
    }
    
    void insertionSort(vector<int>& nums, int begin, int end) {
        for (int i = begin + 1; i < end; i++) {
            for (int k = i - 1; k >= begin; k--) {
                if (nums.at(k) > nums.at(k + 1)) {
                    swap(nums.at(k), nums.at(k + 1));
                }
            }
        }
    }
};
