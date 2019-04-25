// Runtime: 20 ms, faster than 100.00% of C++ online submissions for Permutations II.
// Memory Usage: 9.9 MB, less than 90.35% of C++ online submissions for Permutations II.

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        // Calculate permutation count
        int permutation_count = factorial(nums.size());
        
        unordered_map<int, int> element_repetition;
        
        for (int i = 0; i < nums.size(); i++) {
            if (element_repetition.find(nums.at(0)) == element_repetition.end()) {
                element_repetition[nums.at(i)] = 1;
            } else {
                element_repetition[nums.at(i)]++;
            }
        }
        
        for (auto& count : element_repetition) {
            if (count.second > 1) {
                permutation_count /= factorial(count.second);
            }
        }
        
        
        vector<vector<int>> permutations;
        permutations.push_back(nums);
        
        for (int i = 0; i < permutation_count - 1; i++) {
            nextPermutation(nums);
            permutations.push_back(nums);
        }
        
        return permutations;
    }
    
    int factorial(int n) {
        if (n == 0) {
            return 1;
        }
        return n * factorial(n - 1);
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
