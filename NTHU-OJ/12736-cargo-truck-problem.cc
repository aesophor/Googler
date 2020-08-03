#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Matrix {
 public:
  Matrix(int w = 0, int h = 0) : width_(w), height_(h) {
    for (int i = 0; i < h; i++) {
      data_.push_back({});
      data_.back().resize(w, false);
    }
  }
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
        if (piece.data_[i][j] == true) {
          if (this->data_[row + i][col + j] == true) {
            return false;
          }
          this->data_[row + i][col + j] = true;
        }
      }
    }

    return true;
  }

  bool isValid() const {
    // Check if the objects touch the ground.
    for (const auto& col : data_.back()) {
      if (col == true) {
        return true;
      }
    }

    // There must not be any space around the piece!
    // Check if there are spaces at LHS.
    if (col + piece.width_ + 1 < this->width_) {
      bool hasSpaceAtLhs = true;
      for (int i = 0; i < piece.height_; i++) {
        if (data_[row + i][col + piece.width_ + 1] == true) {
          hasSpaceAtLhs = false;
        }
      }
      if (!hasSpaceAtLhs) {
        return false;
      }
    }

    // Check if there are spaces at RHS.
    if (col - 1 >= 0) {
      bool hasSpaceAtRhs = true;
      for (int i = 0; i < piece.height_; i++) {
        if (data_[row + i][col - 1] == true) {
          hasSpaceAtRhs = false;
        }
      }
      if (!hasSpaceAtRhs) {
        return false;
      }
    }

    return false;
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
  if (current >= (int) pieces.size()) {
    if (puzzle_map.isValid()) {
      result = true;
    }
    return;
  }

  // Try to place current piece into all possible locations.
  for (int i = 0; i < puzzle_map.getHeight(); i++) {
    for (int j = 0; j < puzzle_map.getWidth(); j++) {
      // Don't touch the original puzzle_map here because we want to bruteforce
      // all possibilities, so create another copy!
      Matrix puzzle_map_copy = puzzle_map;

      bool piece_can_fit = puzzle_map_copy.placePieceAt(pieces[current], i, j);

      if (piece_can_fit) {
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


  int num_lengths;
  cin >> num_lengths;

  for (int i = 0; i < num_lengths; i++) {
    int len = 0;
    cin >> len;

    result = false;
    Matrix puzzle_map(len, len);
    solve(puzzle_map, pieces, 0);
    cout << (result ? "Yes" : "No") << endl;
  }
}
