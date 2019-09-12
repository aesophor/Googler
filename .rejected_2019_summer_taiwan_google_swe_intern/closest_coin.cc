#include <iostream>
#include <vector>
#include <queue>

using Pos = std::pair<int, int>;
using GameMap = std::vector<std::vector<char>>;

/**
 * Find the distance of the closest 'o' and 'x'
 * in the specified game map.
 */
int findClosestCoinDist(const GameMap& gameMap) {
  // Find players' positions O(n)
  std::vector<Pos> playersPos;
 
  for (size_t i = 0; i < gameMap.size(); i++) {
    for (size_t j = 0; j < gameMap[i].size(); j++) {
      if (gameMap[i][j] == 'x') {
        playersPos.push_back({i, j});
      }
    }
  }

  // BFS
  std::queue<Pos> q;
  for (const auto& pos : playersPos) {
    q.push(pos);
  }

  const int mapWidth = gameMap[0].size();
  const int mapHeight = gameMap.size();

  int step = 0;
  while (!q.empty()) {
    size_t qSize = q.size();

    for (size_t i = 0; i < qSize; i++) {
      Pos pos = q.front();
      q.pop();

      if (gameMap[pos.first][pos.second] == 'o') {
        return step;
      }

      if (pos.first > 0) {
        q.push({pos.first - 1, pos.second});
      }
      if (pos.first < mapHeight) {
        q.push({pos.first + 1, pos.second});
      }
      if (pos.second > 0) {
        q.push({pos.first, pos.second - 1});
      }
      if (pos.second < mapWidth) {
        q.push({pos.first, pos.second + 1});
      }
    }

    step++;
  }

  return -1;
}

int main() {
  GameMap gameMap = {
    {'o', ' ', ' ', ' ', ' '},
    {' ', ' ', 'x', ' ', 'o'},
    {' ', ' ', ' ', ' ', ' '},
    {'x', ' ', ' ', ' ', ' '},
    {' ', ' ', ' ', 'o', ' '}
  };

  std::cout << findClosestCoinDist(gameMap) << std::endl;
}
