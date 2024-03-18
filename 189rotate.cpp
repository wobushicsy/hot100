#include <vector>

class Solution {
public:
  void rotate(std::vector<int>& nums, int k) {
    int length = nums.size();
    k = k % length;
    k = length - k;
    nums.insert(nums.end(), nums.begin(), nums.begin() + k);
    nums.erase(nums.begin(), nums.begin() + k);
  }
};
