#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Item {
  int V;  // value
  int W;  // weight
};


int N;  // The number of items in the house
int K;  // How much the bag can hold
int result;  // The maximum value we can steal
vector<Item> items;


void collectItem(const vector<Item>& items, int current, bool collect,
                 int backpackW, int backpackV) {
  if (current == (int) items.size()) {
    return;
  }

  if (collect) {
    backpackW += items[current].W;
    backpackV += items[current].V;
  }

  // Stop if backpack weight is too large.
  if (backpackW > K) {
    return;
  }

  // Update max value.
  result = std::max(result, backpackV);

  collectItem(items, current + 1, false, backpackW, backpackV);
  collectItem(items, current + 1, true, backpackW, backpackV);
}

int main() {
  // 1. Collect data from stdin.
  cin >> N >> K;
  
  for (int i = 0; i < N; i++) {
    Item item;
    cin >> item.V >> item.W;
    items.push_back(item);
  }


  // 2. Solve this knapsack problem using recursion.
  collectItem(items, 0, false, 0, 0);
  collectItem(items, 0, true, 0, 0);
  cout << result;
}
