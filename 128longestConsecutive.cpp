#include <vector>
#include <unordered_set>
#include <cmath>
#include <algorithm>

class Solution {
public:
  int longestConsecutive(std::vector<int>& nums) {
    std::unordered_set<int> iset;
    for (auto n : nums) {
      iset.insert(n);
    }

    int tot = 0;
    for (auto n : iset) {
      if (iset.count(n - 1) != 0) {
        continue;
      }
      int cnt = 0;
      while (iset.count(n) != 0) {
        n++;
        cnt++;
      }
      tot = std::max(tot, cnt);
    }

    return tot;
  }
};
