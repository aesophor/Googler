#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Matrix {
 public:
  Matrix() : width_(0), height_(0) {}
  ~Matrix() = default;

  friend istream& operator>> (istream& is, Matrix& matrix) {
    is >> matrix.width_;
    is >> matrix.height_;

    string line;
    for (int i = 0; i < matrix.height_; i++) {
      is >> line;  // For example, line can have the string "-O--"
      matrix.data_.push_back({});  // Create a new vector<bool> at the end of data_.

      for (const auto& ch : line) {
        matrix.data_.back().push_back((ch == '-') ? false : true);
      }
    }
    return is;
  }

  /**
   * Places the given piece beginning at (row, col).
   * return: If the piece can fit into the map, then `true` is returned.
   *         Otherwise, `false` is returned.
   */
  bool placePieceAt(const Matrix& piece, int row, int col) {
    // Check if this piece is too large
    // to place at the given position.
    if (col + piece.width_ > width_ || row + piece.height_ > height_) {
      return false;
    }

    // Try to fit this piece into the map.
    // If we found any error during the process, return `false` immediately.
    for (int i = 0; i < piece.height_; i++) {
      for (int j = 0; j < piece.width_; j++) {
        if (piece.getData()[i][j] == true) {
          if (this->data_[row + i][col + j] == true) {
            return false;
          }
          this->data_[row + i][col + j] = true;
        }
      }
    }
    return true;
  }

  bool isEmpty() const {
    for (const auto& row : data_) {
      for (const auto& col : row) {
        if (col == false) {
          return false;
        }
      }
    }
    return true;
  }

  int getWidth() const { return width_; }
  int getHeight() const { return height_; }
  const vector<vector<bool>>& getData() const { return data_; }

 private:
  int width_;
  int height_;
  vector<vector<bool>> data_;
};


bool result = false;

void solve(Matrix puzzle_map, const vector<Matrix>& pieces, int current) {
  // Try to place current piece into all possible locations.
  for (int i = 0; i < puzzle_map.getHeight(); i++) {
    for (int j = 0; j < puzzle_map.getWidth(); j++) {
      // Don't touch the original puzzle_map here because we want to bruteforce
      // all possibilities, so create another copy!
      Matrix puzzle_map_copy = puzzle_map;

      bool piece_can_fit = puzzle_map_copy.placePieceAt(pieces[current], i, j);
      if (piece_can_fit) {
        if (puzzle_map_copy.isEmpty()) {
          result = true;
          return;
        }
        solve(puzzle_map_copy, pieces, current + 1);
      }
    }
  }
}



int main() {
  int num_pieces;
  cin >> num_pieces;

  // All pieces are stored here.
  vector<Matrix> pieces;

  // Create objects of pieces from stdin.
  for (int i = 0; i < num_pieces; i++) {
    Matrix piece;
    cin >> piece;
    pieces.push_back(piece);
  }


  int num_puzzle_maps;
  cin >> num_puzzle_maps;

  // All puzzle maps are stored here.
  vector<Matrix> puzzle_maps;

  // Create objects of puzzle maps from stdin.
  for (int i = 0; i < num_puzzle_maps; i++) {
    Matrix puzzle_map;
    cin >> puzzle_map;
    puzzle_maps.push_back(puzzle_map);
  }


  // See if we can solve each puzzle map
  for (const auto& puzzle_map : puzzle_maps) {
    result = false;
    solve(puzzle_map, pieces, 0);
    cout << (result ? "Yes" : "No") << endl;
  }
}
