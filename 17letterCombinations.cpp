#include <vector>
#include <string>

#include <unordered_map>

class Solution {
public:
  std::vector<std::string> letterCombinations(std::string digits) {
    if (digits.size() == 0) {
      return {};
    }
    init();
    return letterCombination(digits);
  }

private:
  std::unordered_map<int, std::vector<std::string>> map;

  void init() {
    map[2] = std::vector<std::string>{"a", "b", "c"};
    map[3] = std::vector<std::string>{"d", "e", "f"};
    map[4] = std::vector<std::string>{"g", "h", "i"};
    map[5] = std::vector<std::string>{"j", "k", "l"};
    map[6] = std::vector<std::string>{"m", "n", "o"};
    map[7] = std::vector<std::string>{"p", "q", "r", "s"};
    map[8] = std::vector<std::string>{"t", "u", "v"};
    map[9] = std::vector<std::string>{"w", "x", "y", "z"};
  }

  std::vector<std::string> letterCombination(std::string digits) {
    int size = digits.size();
    if (size == 0) {
      return {""};
    }

    auto src = letterCombination(digits.substr(1));
    std::vector<std::string> ans;
    int digit = digits[0] - '0';
    int sz = map[digit].size();

    for (const std::string &c : map[digit]) {
      for (const std::string &s : src) {
        ans.push_back(c + s);
      }
    }

    return ans;
  }
};
