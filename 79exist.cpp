#include <vector>
#include <string>

#include <unordered_set>

class Solution {
public:
  bool exist(std::vector<std::vector<char>>& board, std::string word) {
    // TODO: 剪枝
    rows = board.size();
    cols = board[0].size();

    std::unordered_set<int> searched;
    for (int i = 0; i < rows; i++) {
      for (int j = 0; j < cols; j++) {
        if (dfs(board, word, 0, i, j, searched)) {
          return true;
        }
      }
    }

    return false;
  }

private:
  int rows;
  int cols;

  bool onBoard(int i, int j) {
    return i >= 0 && i < rows && j >= 0 && j < cols;
  }

  int h(int i, int j) {
    return (i << 10) + j;
  }

  bool dfs(std::vector<std::vector<char>> &board, std::string &word, int idx, int i, int j,
           std::unordered_set<int> &searched) {
    char c = word[idx];
    if (board[i][j] != c) {
      return false;
    }
    if (idx == word.size() - 1) {
      return true;
    }

    std::vector<int> offset{-1, 1};
    searched.insert(h(i, j));
    for (int off : offset) {
      if (onBoard(i + off, j) && searched.count(h(i + off, j)) == 0) {
        if (dfs(board, word, idx + 1, i + off, j, searched)) {
          return true;
        }
      }
      if (onBoard(i, j + off) && searched.count(h(i, j + off)) == 0) {
        if (dfs(board, word, idx + 1, i, j + off, searched)) {
          return true;
        }
      }
    }
    searched.erase(h(i, j));

    return false;
  }
};
