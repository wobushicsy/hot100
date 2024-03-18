#include <vector>
#include <algorithm>
#include <map>

class Solution {
public:
  std::vector<std::vector<int>> threeSum(std::vector<int>& nums) {
    std::vector<std::vector<int>> ans;

    std::sort(nums.begin(), nums.end());
    int length = nums.size();
    for (int i = 0; i < length; i++) {
      if (i > 0 && nums[i] == nums[i - 1]) {
        continue;
      }

      int l = i + 1;
      int r = length - 1;

      while (l < r) {
        int tot = nums[i] + nums[l] + nums[r];
        if (tot > 0) {
          r--;
        } else if (tot < 0) {
          l++;
        } else {
          ans.push_back({nums[i], nums[l], nums[r]});
          while (l + 1 < length && nums[l] == nums[++l])
            ;
          while (r - 1 > 0 && nums[r] == nums[--r])
            ;
        }
      }
    }
    return ans;
  }
};