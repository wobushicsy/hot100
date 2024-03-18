#include <vector>

class Solution {
public:
  std::vector<int> spiralOrder(std::vector<std::vector<int>>& matrix) {
    int left = 0;
    int right = matrix[0].size();
    int bot = 0;
    int top = matrix.size();
    int state = 0;

    int row = 0;
    int col = 0;

    std::vector<int> ans;
    while (left < right && bot < top) {
      switch (state) {
      case 0:
        for (int i = left; i < right; i++) {
          ans.push_back(matrix[row][i]);
        }
        state = 1;
        col = right - 1;
        bot++;
        break;
      case 1:
        for (int i = bot; i < top; i++) {
          ans.push_back(matrix[i][col]);
        }
        state = 2;
        row = top - 1;
        right--;
        break;
      case 2:
        for (int i = right - 1; i >= left; i--) {
          ans.push_back(matrix[row][i]);
        }
        state = 3;
        col = left;
        top--;
        break;
      case 3:
        for (int i = top - 1; i >= bot; i--) {
          ans.push_back(matrix[i][col]);
        }
        state = 0;
        row = bot;
        left++;
        break;
      default:
        break;
      }
    }

    return ans;
  }
};

int main() {
  std::vector<std::vector<int>> matrix{{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
  Solution sol;
  sol.spiralOrder(matrix);
}
