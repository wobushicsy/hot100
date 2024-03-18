#include <vector>

#include <algorithm>

class Solution {
public:
  int maxSubArray(std::vector<int>& nums) {
    int length = nums.size();
    
    int dp = nums[0];
    int ans = dp;
    for (int i = 1; i < length; i++) {
        dp = std::max(dp + nums[i], nums[i]);
        if (dp > ans) {
            ans = dp;
        }
    }

    return ans;
  }
};
