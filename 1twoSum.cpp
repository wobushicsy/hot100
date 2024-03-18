#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> twoSum(vector<int>& nums, int target) {
    std::vector<int> ans;
    std::unordered_map<int, int> iimap;
    int sz = nums.size();
    for (int i = 0; i < sz; i++) {
      if (iimap.count(target - nums[i]) != 0) {
        ans.push_back(iimap[target - nums[i]]);
        ans.push_back(i);
      }
      iimap[nums[i]] = i;
    }
    return ans;
  }
};
