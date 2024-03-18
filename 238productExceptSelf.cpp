#include <vector>

class Solution {
public:
  std::vector<int> productExceptSelf(std::vector<int>& nums) {
    int length = nums.size();
    std::vector<int> ans{nums.front()};
    ans.reserve(length);

    for (int i = 1; i < length; i++) {
      ans.emplace_back(ans.back() * nums[i]);
    }

    ans.back() = ans[length - 2];
    int num = nums.back();
    for (int i = length - 2; i > 0; i--) {
      ans[i] = ans[i - 1] * num;
      num *= nums[i];
    }
    ans[0] = num;

    return ans;
  }
};