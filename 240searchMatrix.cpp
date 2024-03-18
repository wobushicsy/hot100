#include <vector>
#include <iostream>

class Solution {
public:
  bool searchMatrix(std::vector<std::vector<int>>& matrix, int target) {
    for (const auto &row : matrix) {
      if (binarySearch(row, target)) {
        return true;
      }
    }

    return false;
  }

private:
  bool binarySearch(const std::vector<int> &vec, int target) {
    int l = 0;
    int r = vec.size();

    while (l < r) {
      int mid = (l + r) / 2;
      if (vec[mid] == target) {
        return true;
      }
      if (vec[mid] > target) {
        r = mid;
      } else {
        l = mid + 1;
      }
    }

    return false;
  }
};

int main() {
  std::vector<std::vector<int>> vec{{1,4,7,11,15},{2,5,8,12,19},{3,6,9,16,22},{10,13,14,17,24},{18,21,23,26,30}};
  Solution sol;
  std::cout << sol.searchMatrix(vec, 5) << std::endl;
}
