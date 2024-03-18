#include <vector>

class Solution {
public:
  int trap(std::vector<int>& height) {
    int cap = 0;

    int length = height.size();
    if (length < 3) {
      return 0;
    }

    int l = 0;
    while (l + 1 < length && height[l + 1] >= height[l]) {
      l++;
    }

    while (l < length) {
      int r = l + 1;
      int secHeight = 0;
      int idx = -1;
      while (r < length && height[r] < height[l]) {
        if (height[r] > secHeight) {
          secHeight = height[r];
          idx = r;
        }
        r++;
      }

      if (r != length) {
        int waterHeight = height[l];
        for (int i = l; i < r; i++) {
          cap += std::max(waterHeight - height[i], 0);
        }
        l = r;
      } else {
        if (idx == -1) {
          break;
        }
        int waterHeight = secHeight;
        r = idx;
        for (int i = l; i < r; i++) {
          cap += std::max(waterHeight - height[i], 0);
        }
        l = idx;
      }
    }

    return cap;
  }
};
