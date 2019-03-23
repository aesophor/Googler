// Runtime: 908 ms, faster than 5.17% of C++ online submissions for Is Graph Bipartite?.
// Memory Usage: 24.7 MB, less than 5.30% of C++ online submissions for Is Graph Bipartite?.

class Solution {
public:
  bool isBipartite(vector<vector<int>>& graph) {
    // This graph may be disconnected, starting dfs at 0
    // will fuck up your dfs.
    for (int i = 0; i < graph.size(); i++) {
      colors_.clear();
      dfs(graph, i, kRed);
    }
    return result_;
  }
  
private:
  void dfs(vector<vector<int>>& graph, int node, bool color) {
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
  
  static const bool kRed = true; // red = true, blue = false
  
  unordered_map<int, bool> colors_;
  bool result_ = true;
};
