#include <vector>

class Solution {
public:
  void moveZeroes(std::vector<int>& nums) {
    int length = nums.size();
    int pnum = 0;
    int pzero = 0;

    while (pnum < length && pzero < length) {
      while (pzero < length && nums[pzero] != 0) {
        pzero++;
      }
      if (pzero >= length) {
        break;
      }
      pnum = pzero + 1;
      while (pnum < length && nums[pnum] == 0) {
        pnum++;
      }
      if (pnum >= length) {
        break;
      }
      auto tmp = nums[pnum];
      nums[pnum] = nums[pzero];
      nums[pzero] = tmp;
    }
  }
};
