#include <vector>
#include <iostream>

#include <algorithm>

class Solution {
public:
  std::vector<std::vector<int>> merge(std::vector<std::vector<int>>& intervals) {
    std::sort(intervals.begin(), intervals.end(), [](std::vector<int> &v1, std::vector<int> &v2) -> bool {
      return v1.front() < v2.front();
    });
    
    auto &v = intervals.front();
    std::vector<std::vector<int>> ans{{v.front(), v.back()}};

    for (const auto &vec : intervals) {
      int f = vec.front();
      int b = vec.back();
      if (f >= ans.back().front() && f <= ans.back().back()) {
        ans.back().back() = std::max(ans.back().back(), b);
      } else {
        ans.emplace_back(vec);
      }
    }

    return ans;
  }
};

int main() {
  Solution sol;
  std::vector<std::vector<int>> vec{{1, 4}, {0, 2}, {3, 5}};
  for (auto vec : sol.merge(vec)) {
    if(vec.size() != 2) {
      std::cout << "SIZE ERROR\n";
      return 0;
    }
    std::cout << vec.front() << " " << vec.back() << std::endl;
  }
}
