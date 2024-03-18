#include <vector>

#include <unordered_set>

class Solution {
public:
  void setZeroes(std::vector<std::vector<int>>& matrix) {
    int rows = matrix.size();
    int cols = matrix[0].size();

    std::unordered_set<int> row;
    std::unordered_set<int> col;

    for (int i = 0; i < rows; i++) {
      for (int j = 0; j < cols; j++) {
        if (matrix[i][j] == 0) {
          row.insert(i);
          col.insert(j);
        }
      }
    }

    for (int r : row) {
      for (int i = 0; i < cols; i++) {
        matrix[r][i] = 0;
      }
    }

    for (int c : col) {
      for (int i = 0; i < rows; i++) {
        matrix[i][c] = 0;
      }
    }
  }
};