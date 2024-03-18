#include <vector>
#include <iostream>

#include <cstring>

#define MAX_SIZE 100002

int arr[MAX_SIZE] = {0};

class Solution {
public:
  int firstMissingPositive(std::vector<int>& nums) {
    memset(arr, 0, sizeof(arr));
    for (int i = 0; i < MAX_SIZE; i++) {
      if (arr[i] != 0) {
        return -1;
      }
    }
    for (int num : nums) {
      if (num <= 0 || num >= MAX_SIZE) {
        continue;
      }
      arr[num] = 1;
    }

    int ans = 1;
    for (int i = 1; i < MAX_SIZE; i++) {
      if (arr[i] == 0) {
        ans = i;
        break;
      }
    }

    return ans;
  }
};

int main() {
  std::vector<int> nums{3, 4, -1, 1};
  Solution sol;
  std::cout << sol.firstMissingPositive(nums) << std::endl;
}
