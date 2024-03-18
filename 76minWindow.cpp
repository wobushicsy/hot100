#include <string>
#include <iostream>

#include <unordered_map>
#include <list>

using cimap = std::unordered_map<char, int>;

class Solution {
public:
  std::string minWindow(std::string s, std::string t) {
    cimap target;
    int tLength = t.size();
    for (int i = 0; i < tLength; i++) {
      char c = t[i];
      target[c]++;
    }

    cimap src;
    std::list<int> indices;

    int l = -1;
    int r = 1000000;

    int sLength = s.size();
    for(int i = 0; i < sLength; i++) {
      char c = s[i];
      if (target.count(c) == 0) {
        continue;
      }
      src[c]++;
      indices.push_back(i);

      while (isCovered(target, src)) {
        int f = indices.front();
        int b = indices.back();
        if (b - f < r - l) {
          r = b;
          l = f;
        }

        indices.pop_front();
        src[s[f]]--;
      }
    }

    return l == -1 ? "" : s.substr(l, r - l + 1);
  }

private:
  bool isCovered(const cimap &target, const cimap &src) {
    for (const auto &[c, cnt] : target) {
      if (src.count(c) == 0 || src.at(c) < cnt) {
        return false;
      }
    }

    return true;
  }
};

int main() {
  Solution sol;
  std::cout << sol.minWindow("a", "aa") << std::endl;
}
