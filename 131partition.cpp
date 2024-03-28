#include <vector>
#include <string>

class Solution {
public:
  std::vector<std::vector<std::string>> partition(std::string s) {
    pre(s);
    n = s.size();
    dfs(s, 0);
    return ans;
  }

private:
  bool isReverse[16][16];
  int n;
  std::vector<std::vector<std::string>> ans;
  std::vector<std::string> vec;

  void pre(std::string s) {
    for (int i = 0; i < 16; i++) {
      for (int j = 0; j < 16; j++) {
        isReverse[i][j] = false;
      }
    }
    int len = s.size();
    for (int i = 0; i < len; i++) {
      for (int j = i; j < len; j++) {
        isReverse[i][j] = pre(s, i, j);
      }
    }
  }

  bool pre(std::string &s, int l, int r) {
    if (l >= r) {
      return true;
    }
    return s[l] == s[r] && pre(s, l + 1, r - 1);
  }

  void dfs(std::string &s, int i) {
    if (i == n) {
      ans.push_back(vec);
      return;
    }
    for (int j = i; j < n; j++) {
      if (!isReverse[i][j]) {
        continue;
      }
      vec.push_back(s.substr(i, j - i + 1));
      dfs(s, j + 1);
      vec.pop_back();
    }
  }
};

#include <iostream>

int main() {
  Solution sol;
  for (const auto &vec : sol.partition("asds")) {
    for (const auto &s : vec) {
      std::cout << s << " ";
    }
    std::cout << "\n";
  }
}
