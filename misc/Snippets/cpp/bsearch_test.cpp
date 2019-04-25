#include <iostream>
#include <vector>

using namespace std;

int binarySearch(vector<int>& nums, int left, int right, int target) {
    cout << "left: " << left << " | right: " << right << " | target: " << target << endl;
    if (left == right) {
        return (nums.at(left) == target) ? left : -1;
    }

    int mid = (left + right) / 2;

    if (nums.at(mid) < target) {
        return binarySearch(nums, mid + 1, right, target);
    } else if (nums.at(mid) == target) {
        return mid;
    } else {
        return binarySearch(nums, left, mid - 1, target);
    }
}

int main() {
    vector<int> nums = {2,2};
    cout << binarySearch(nums, 0, nums.size() - 1, 1) << endl;
}
