#include <vector>
#include <algorithm>

class Solution {
public:
  std::vector<std::vector<int>> combinationSum(std::vector<int>& candidates, int target) {
    std::vector<int> com;
    dfs(candidates, target, com);
    return ans;
}

private:
  std::vector<std::vector<int>> ans;

  void dfs(std::vector<int> &candidates, int target, std::vector<int> com) {
    if (target == 0) {
      ans.push_back(com);
      return;
    }
    if (target < 0) {
      return;
    }

    for (int num : candidates) {
      if (!com.empty() && num < com.back()) {
        continue;
      }
      com.push_back(num);
      dfs(candidates, target - num, com);
      com.pop_back();
    }
  }
};

int main() {
  Solution sol;
  std::vector<int> candidates{2, 3, 5};
  sol.combinationSum(candidates, 8);
}
