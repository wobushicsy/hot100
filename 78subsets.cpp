#include <vector>

class Solution {
public:
  std::vector<std::vector<int>> subsets(std::vector<int>& nums) {
    return subset(nums);
  }

private:
  std::vector<std::vector<int>> subset(std::vector<int> nums) {
    if (nums.empty()) {
      return {{}};
    }

    int num = nums.back();
    nums.pop_back();

    auto s = subset(nums);
    auto s1 = s;
    for (auto vec : s) {
      vec.push_back(num);
      s1.push_back(vec);
    }

    return s1;
  }
};
