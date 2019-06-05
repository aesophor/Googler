#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

namespace {

vector<int> split(const string& s, const char delimiter=' ') {
  std::stringstream ss(s);
  string t;
  vector<int> tokens;

  while (std::getline(ss, t, delimiter)) {
    if (t.length() > 0) {
      tokens.push_back(std::stoi(t));
    }
  }
  return tokens;
}

} // namespace


int main() {
  string s;
  while (std::getline(cin, s)) {
    vector<int> nums = ::split(s);
    std::sort(nums.begin(), nums.end());

    int target = nums[nums.size() / 2];
    
    // count the freq of this bitch
    int freq = 0;
    for (auto n : nums) {
      if (n == target) {
        freq++;
      }
    }
    if (freq > std::ceil(nums.size() / 2)) {
      cout << target << endl;
    } else {
      cout << "n/a" << endl;
    }
  }
}
