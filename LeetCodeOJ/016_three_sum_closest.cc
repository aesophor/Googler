// Runtime: 12 ms, faster than 75.19% of C++ online submissions for 3Sum Closest.
// Memory Usage: 9.4 MB, less than 73.26% of C++ online submissions for 3Sum Closest.

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        std::sort(nums.begin(), nums.end());
        int size = nums.size();
        bool min_distance_init = false;
        int min_distance = 0;
        int closest_sum = 0;
        
        for (int i = 0; i < size; i++) {
            if (i > 0 && nums.at(i) == nums.at(i - 1)) {
                continue;
            }
            
            int pfront = i + 1;
            int pback = size - 1;
            
            while (pfront < pback) {
                int two_sum = nums.at(pfront) + nums.at(pback);
                int complement = target - nums.at(i);
                
                //  2, 3, 4  sum = 9
                // let target = 7
                // distance = abs(7 - 9)
                int distance = std::abs(target - (nums.at(i) + two_sum));
                
                if (!min_distance_init) {
                    min_distance_init = true;
                    min_distance = distance;
                    closest_sum = nums.at(i) + two_sum;
                } else if (std::min(min_distance, distance) == distance) {
                    min_distance = std::min(min_distance, distance);
                    closest_sum = nums.at(i) + two_sum;
                }
                
                if (two_sum == complement) { // just in case
                    return target;
                } else if (two_sum < complement) {
                    pfront++;
                } else { // sum > complement
                    pback--;
                }
            }
        }
        
        return closest_sum;
    }
};
