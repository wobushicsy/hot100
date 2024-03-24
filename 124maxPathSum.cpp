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
#include <algorithm>

class Solution {
public:
  int maxPathSum(TreeNode* root) {
    if (root == nullptr) {
      return 0;
    }
    int lval = dfs(root->left);
    int rval = dfs(root->right);
    int ans = std::max(root->val + lval + rval, root->val + lval);
    ans = std::max(ans, root->val + rval);
    ans = std::max(ans, root->val);
    if (root->left != nullptr) {
      ans = std::max(ans, maxPathSum(root->left));
    }
    return root->right != nullptr ? std::max(ans, maxPathSum(root->right)) : ans;
  }

private:
  int dfs(TreeNode *root) {
    if (root == nullptr) {
      return 0;
    }
    int lval = dfs(root->left);
    int rval = dfs(root->right);
    int val = root->val;
    int ans = std::max(lval, rval);
    return std::max(val, val + ans);
  }
};
