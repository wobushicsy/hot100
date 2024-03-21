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

#include <climits>

using ll = long long;

class Solution {
public:
  bool isValidBST(TreeNode* root) {
    return isValidBST(root, LONG_LONG_MIN, LONG_LONG_MAX);
  }

private:
  bool isValidBST(TreeNode *root, ll lb, ll ub) {
    if (root == nullptr) {
      return true;
    }
    ll val = root->val;
    if (val <= lb || val >= ub) {
      return false;
    }
    if (!isValidBST(root->left, lb, val)) {
      return false;
    }
    return isValidBST(root->right, val, ub);
  }
};
