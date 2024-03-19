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
  std::vector<int> inorderTraversal(TreeNode* root) {
    std::vector<int> ans;
    traversal(root, ans);
    return ans;
  }

private:
  void traversal(TreeNode *n, std::vector<int> &ans) {
    if (n == nullptr) {
      return;
    }
    traversal(n->left, ans);
    ans.push_back(n->val);
    traversal(n->right, ans);
  }
};