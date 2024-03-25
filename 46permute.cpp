#include <vector>

#include <algorithm>

class Solution {
public:
  std::vector<std::vector<int>> permute(std::vector<int>& nums) {
    return traceback(nums);
  }

private:
  std::vector<std::vector<int>> traceback(std::vector<int> nums) {
    int size = nums.size();
    if (size == 1) {
      return {nums};
    }

    std::vector<std::vector<int>> ans;
    for (int i = 0; i < size; i++) {
      int num = nums[i];
      nums.erase(std::find(nums.begin(), nums.end(), num));
      for (auto vec : traceback(nums)) {
        vec.push_back(num);
        ans.push_back(vec);
      }
      nums.insert(nums.begin() + i, num);
    }

    return ans;
  }
};
