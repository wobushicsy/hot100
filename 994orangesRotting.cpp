#include <vector>

#include <unordered_map>

class Solution {
public:
  int orangesRotting(std::vector<std::vector<int>>& grid) {
    rows = grid.size();
    cols = grid[0].size();

    int round = 0;
    int state;
    while ((state = finished(grid)) == 0) {
      round++;
      std::unordered_map<int, std::vector<int>> bads;
      for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
          if (grid[i][j] == 2) {
            bads[i].push_back(j);
          }
        }
      }

      for (auto &[i, js] : bads) {
        for (auto j : js) {
          int is[] = {-1, 1};
          int js[] = {-1, 1};
          for (int x : is) {
            if (inGrid(i + x, j) && grid[i + x][j] == 1) {
              grid[i + x][j] = 2;
            }
            if (inGrid(i, j + x) && grid[i][j + x] == 1) {
              grid[i][j + x] = 2;
            }
          }
        }
      }
    }

    return state == 1 ? round : -1;
  }

private:
  int rows;
  int cols;

  bool inGrid(int i, int j) {
    return i >= 0 && i < rows && j >= 0 && j < cols;
  }

  int finished(std::vector<std::vector<int>> &grid) {
    int is[] = {-1, 1};
    int goods = 0;
    for (int i = 0; i < rows; i++) {
      for (int j = 0; j < cols; j++) {
        if (grid[i][j] != 1) {
          continue;
        }
        goods++;
        for (int x : is) {
          if (inGrid(i + x, j) && grid[i + x][j] == 2) {
            return 0;
          }
          if (inGrid(i, j + x) && grid[i][j + x] == 2) {
            return 0;
          }
        }
      }
    }

    return goods == 0 ? 1 : 2;
  }
};
