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
#include <vector>

using ll = long long;

class Solution {
public:
  int pathSum(TreeNode* root, int targetSum) {
    return pathSum(root, targetSum, {});
  }

private:
  int pathSum(TreeNode *root, int targetSum, std::vector<ll> nums) {
    if (root == nullptr) {
      return 0;
    }
    ll val = root->val;
    int cnt = val == targetSum ? 1 : 0;
    for (ll &num : nums) {
      num += val;
      if (num == targetSum) {
        cnt++;
      }
    }
    nums.push_back(val);
    return cnt + pathSum(root->left, targetSum, nums) + pathSum(root->right, targetSum, nums);
  }
};
