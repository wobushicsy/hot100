#include <cstddef>

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include <vector>
#include <unordered_set>

class Solution {
public:
  TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    auto ps = dfs(root, p);
    std::unordered_set<TreeNode *> np;
    for (auto node : ps) {
      np.insert(node);
    }
    auto qs = dfs(root, q);
    auto ans = root;
    for (auto node : qs) {
      if (np.count(node) != 0) {
        ans = node;
        break;
      }
    }

    return ans;
  }

private:
  std::vector<TreeNode *> dfs(TreeNode *root, TreeNode *p) {
    if (root == p) {
      return {p};
    }
    if (root == nullptr) {
      return {};
    }
    auto l = dfs(root->left, p);
    if (!l.empty()) {
      l.push_back(root);
      return l;
    }
    auto r = dfs(root->right, p);
    if (!r.empty()) {
      r.push_back(root);
      return r;
    }
    return {};
  } 
};
