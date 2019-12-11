#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int GetTotalWaitingTime(const vector<int>& jobs) {
  // DP
  vector<int> waiting_time(jobs.size());
  waiting_time[0] = 0;

  int t = 0;
  for (int i = 1; i < (int) jobs.size(); i++) {
    t += jobs[i - 1];
    waiting_time[i] = t;
  }

  int sum = 0;
  for (auto n : waiting_time) {
    sum += n;
  }
  return sum;
}

int main() {
  int count = 0;
  cin >> count;

  for (int i = 0; i < count; i++) {
    int num_jobs = 0;
    cin >> num_jobs;

    vector<int> jobs(num_jobs);
    for (int i = 0; i < num_jobs; i++) {
      cin >> jobs[i];
    }

    char scheduler_type = 0x00;
    cin >> scheduler_type;

    switch (scheduler_type) {
      case 'A':
        cout << GetTotalWaitingTime(jobs) << endl;
        break;
      case 'B':
        std::sort(jobs.begin(), jobs.end());
        cout << GetTotalWaitingTime(jobs) << endl;
        break;
      default:
        cout << "error" << endl;
        break;
    }
  }
}
