#include <vector>
#include <algorithm>
#include <iostream>

class Solution {
public:
  int maxArea(std::vector<int>& height) {
    int m = 0;
    int l = 0;
    int r = height.size() - 1;

    while (l < r) {
      int h = std::min(height[l], height[r]);
      int cap = h * (r - l);
      if (cap > m) {
        m = cap;
      }

      height[l] < height[r] ? l++ : r--;
    }

    return m;
  }
};

int main() {
  Solution sol;
  std::vector<int> vec{1,8,6,2,5,4,8,3,7};
  std::cout << sol.maxArea(vec);
}
