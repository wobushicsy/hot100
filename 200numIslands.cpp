#include <vector>

#include <unordered_set>

class Solution {
public:
  int numIslands(std::vector<std::vector<char>>& grid) {
    rows = grid.size();
    cols = grid[0].size();
    int nums = 0;
    for (int i = 0; i < rows; i++) {
      for (int j = 0; j < cols; j++) {
        if (grid[i][j] == '1' && searched.count(hf(i, j)) == 0) {
          nums++;
          dfs(grid, i, j);
        }
      }
    }

    return nums;
  }

private:
  std::unordered_set<int> searched;
  int rows;
  int cols;

  int hf(int i, int j) {
    return i * 1000 + j;
  }

  bool inGrid(std::vector<std::vector<char>> &grid, int i, int j) {
    return i >= 0 && i < rows && j >= 0 && j < cols;
  }

  void dfs(std::vector<std::vector<char>> &grid, int i, int j) {
    if (grid[i][j] != '1') {
      return;
    }
    searched.insert(hf(i, j));
    if (searched.count(hf(i + 1, j)) == 0 && inGrid(grid, i + 1, j)) {
      dfs(grid, i + 1, j);
    }
    if (searched.count(hf(i - 1, j)) == 0 && inGrid(grid, i - 1, j)) {
      dfs(grid, i - 1, j);
    }
    if (searched.count(hf(i, j + 1)) == 0 && inGrid(grid, i, j + 1)) {
      dfs(grid, i, j + 1);
    }
    if (searched.count(hf(i, j - 1)) == 0 && inGrid(grid, i, j - 1)) {
      dfs(grid, i, j - 1);
    }
  }
};
