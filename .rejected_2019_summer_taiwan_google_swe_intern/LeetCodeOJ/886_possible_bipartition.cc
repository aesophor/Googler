// Runtime: 228 ms, faster than 56.18% of C++ online submissions for Possible Bipartition.
// Memory Usage: 53.2 MB, less than 60.00% of C++ online submissions for Possible Bipartition.

class Solution {
public:
  bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
    // Build the adjacency lists that represents the graph
    // according to how people dislike one another.
    vector<vector<int>> adjacency_lists(N);
    
    for (auto& dislike : dislikes) {
      // Shift left by 1 to match zero indexing.
      int node1 = dislike.at(0) - 1;
      int node2 = dislike.at(1) - 1;
      
      // Set both nodes to be connected.
      adjacency_lists.at(node1).push_back(node2);
      adjacency_lists.at(node2).push_back(node1);
    }
    
    // Perform dfs
    for (int i = 0; i < N; i++) {
      if (colors_.find(i) == colors_.end()) {
        dfs(adjacency_lists, i, kRed);
      }
    }
    return result_;
  }
  
private:
  void dfs(vector<vector<int>>& graph, int node, int color) {
    // Stop if this node is already colored.
    if (colors_.find(node) != colors_.end()) {
      return;
    }
    
    colors_[node] = color;
    
    for (auto adjacent_node : graph.at(node)) {
      dfs(graph, adjacent_node, !color);
      
      if (colors_.at(adjacent_node) == color) {
        result_ = false;
      }
    }
  }
  
  static const bool kRed = true; // true = red, false = blue.
  unordered_map<int, bool> colors_;
  bool result_ = true;
};

// N = 4, dislikes = [[1,2],[1,3],[2,4]]
// adj_list = [[2,3],[1,4],[1],[2]]

// scan 1 ~ 4
// 1, 2

// node1 = 0;
// node2 = 2;

