#include <vector>

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
  TreeNode* sortedArrayToBST(std::vector<int>& nums) {
    return sortedArrayToBST(nums, 0, nums.size());
  }

private:
  TreeNode* sortedArrayToBST(std::vector<int>& nums, int l, int r) {
    // [l, r)
    if (l >= r) {
      return nullptr;
    }
    int mid = (l + r) / 2;
    return new TreeNode(nums[mid], sortedArrayToBST(nums, l, mid), sortedArrayToBST(nums, mid + 1, r));
  }
};
