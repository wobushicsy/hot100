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
#include <utility>

class Solution {
public:
  void flatten(TreeNode* root) {
    leftOrder(root);
  }

private:
  std::pair<TreeNode *, TreeNode *> leftOrder(TreeNode *root) {
    if (root == nullptr) {
      return {nullptr, nullptr};
    }
    auto [lhead, lend] = leftOrder(root->left);
    auto [rhead, rend] = leftOrder(root->right);
    root->left = nullptr;
    root->right = nullptr;

    if (lhead == nullptr) {
      root->right = rhead;
    } else {
      root->right = lhead;
      lend->right = rhead;
    }
    return {root, rend != nullptr ? rend : lend != nullptr ? lend : root};
  }
};
