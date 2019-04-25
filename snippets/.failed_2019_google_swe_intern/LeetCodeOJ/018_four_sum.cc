// Runtime: 60 ms, faster than 32.62% of C++ online submissions for 4Sum.
// Memory Usage: 10.7 MB, less than 63.52% of C++ online submissions for 4Sum.

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        // Reduce four sum to multiple three sum problems, and
        // reduce each three sum to multiple two sum problems.
        std::sort(nums.begin(), nums.end());
        int size = nums.size();
        vector<vector<int>> result;
        
        for (int i = 0; i < size; i++) {
            if (i > 0 && nums.at(i) == nums.at(i - 1)) {
                continue;
            }
            
            for (int j = i + 1; j < size; j++) {
                if (j > i + 1 && nums.at(j) == nums.at(j - 1)) {
                    continue;
                }
                
                int pfront = j + 1;
                int pback = size - 1;
                
                while (pfront < pback) {
                    int sum = nums.at(pfront) + nums.at(pback);
                    int complement = target - nums.at(i) - nums.at(j);
                    
                    if (sum == complement) { // means the sum of these 4 numbers == target
                        result.push_back({ nums.at(i), nums.at(j), nums.at(pfront), nums.at(pback) });
                        
                        // Move pfront right to the next "different" element
                        do { pfront++; } while (pfront < pback && nums.at(pfront - 1) == nums.at(pfront));
                        do { pback--; } while (pfront < pback && nums.at(pback) == nums.at(pback + 1));
                    } else if (sum < complement) {
                        do { pfront++; } while (pfront < pback && nums.at(pfront - 1) == nums.at(pfront));
                    } else { // sum > complement
                        do { pback--; } while (pfront < pback && nums.at(pback) == nums.at(pback + 1));
                    }
                }
                
            }
            
        }
        
        return result;
    }
};
