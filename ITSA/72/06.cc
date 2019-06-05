#include <iostream>
#include <string>
#include <sstream>
#include <vector>

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

int countP(int n, int k) { 
  // Base cases 
  if (n == 0 || k == 0 || k > n) 
    return 0; 
  if (k == 1 || k == n) 
    return 1; 
  
  return  k*countP(n-1, k) + countP(n-1, k-1); 
} 

} // namespace

int main() {
  string s;
  while (std::getline(cin, s)) {
    vector<int> input = ::split(s, ',');
    cout << countP(input[0], input[1]) << endl;
  }
}
