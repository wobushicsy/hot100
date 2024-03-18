#include <vector>
#include <iostream>

#include <set>

class Solution {
public:
  std::vector<int> maxSlidingWindow(std::vector<int>& nums, int k) {
    std::multiset<int> slides;
    for (int i = 0; i < k; i++) {
      slides.insert(nums[i]);
    }

    int idx = 0;
    int length = nums.size();
    std::vector<int> ans{*slides.rbegin()};
    for (int i = 1; i + k <= length; i++) {
      slides.insert(nums[i + k - 1]);
      slides.erase(slides.find(nums[i - 1]));
      ans.push_back(*slides.rbegin());
    }

    return ans;
  }
};

int main() {
  Solution sol;
  std::vector<int> vec{-7,-8,7,5,7,1,6,0};
  auto ans = sol.maxSlidingWindow(vec, 4);
  for (auto num : ans) {
    std::cout << num << std::endl;
  }
}