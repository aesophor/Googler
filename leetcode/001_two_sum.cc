#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        for (int i = 0; i < (int) nums.size(); i++) {
            for (int j = i + 1; j < (int) nums.size(); j++) {
                if (nums.at(i) + nums.at(j) == target) {
                    return vector<int> { i, j };
                }
            }
        }
        return vector<int> { -1, -1 };
    }
};

int main() {
    vector<int> input = { 3, 2, 4 };
    for (auto num : Solution().twoSum(input, 6)) {
        cout << num << endl;
    }
}
