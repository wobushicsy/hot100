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
  std::vector<int> rightSideView(TreeNode* root) {
    levelOrder(root, 0);
    return ans;
  }

private:
  std::vector<int> ans;

  void levelOrder(TreeNode *root, int depth) {
    if (root == nullptr) {
      return;
    }
    if (ans.size() == depth) {
      ans.push_back(root->val);
    }
    levelOrder(root->right, depth + 1);
    levelOrder(root->left, depth + 1);
  }
};
