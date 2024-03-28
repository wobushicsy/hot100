#include <vector>
#include <string>

class Solution {
public:
  std::vector<std::string> generateParenthesis(int n) {
    std::vector<std::string> ans{""};
    return generate(n, 0, 0, ans);
  }

private:
  std::vector<std::string> generate(int n, int ln, int rn, std::vector<std::string> vec) {
    if (ln == rn) {
      if (ln == n) {
        return vec;
      }
      for (auto &s : vec) {
        s += "(";
      }
      return generate(n, ln + 1, rn, vec);
    }

    if (ln == n) {
      for (auto &s : vec) {
        s += ")";
      }
      return generate(n, ln, rn + 1, vec);
    }
    std::vector<std::string> ans;
    auto s1 = vec;
    for (auto &s : s1) {
      s += "(";
    }
    for (auto s : generate(n, ln + 1, rn, s1)) {
      ans.push_back(s);
    }
    for (auto &s : vec) {
      s += ")";
    }
    for (auto s : generate(n, ln, rn + 1, vec)) {
      ans.push_back(s);
    }
    return ans;
  }
};
