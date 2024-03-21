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
#include <deque>

class Solution {
public:
  std::vector<std::vector<int>> levelOrder(TreeNode* root) {
    std::vector<std::vector<int>> ans;
    std::deque<TreeNode *> lq;
    std::deque<TreeNode *> nq;

    lq.push_back(root);
    while (!lq.empty()) {
      std::vector<int> vec;
      while (!lq.empty()) {
        auto node = lq.front();
        lq.pop_front();
        if (node == nullptr) {
          continue;
        }
        nq.push_back(node->left);
        nq.push_back(node->right);
        vec.push_back(node->val);
      }
      lq = nq;
      nq.clear();
      if (!vec.empty()) {
        ans.emplace_back(vec);
      }
    }

    return ans;
  }
};
