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
#include <algorithm>

class Solution {
public:
  TreeNode* buildTree(std::vector<int>& preorder, std::vector<int>& inorder) {
    if (inorder.empty()) {
      return nullptr;
    }
    int rv = preorder.front();
    preorder.erase(preorder.begin());
    TreeNode *root = new TreeNode(rv);
    auto iter = std::find(inorder.begin(), inorder.end(), rv);
    auto linorder = std::vector<int>(inorder.begin(), iter);
    auto rinorder = iter != inorder.end() ? std::vector<int>(iter + 1, inorder.end()) : std::vector<int>{};

    root->left = buildTree(preorder, linorder);
    root->right = buildTree(preorder, rinorder);
    return root;
  }
};
