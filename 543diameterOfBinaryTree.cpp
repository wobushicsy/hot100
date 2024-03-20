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
#include <unordered_map>
#include <algorithm>

class Solution {
public:
  int diameterOfBinaryTree(TreeNode* root) {
    if (root == nullptr) {
      return 0;
    }
    maxDepth(root);
    return findDiameterOfBinaryTree(root);
  }

private:
  std::unordered_map<TreeNode *, int> depth;

  int maxDepth(TreeNode *root) {
    if (root == nullptr) {
      depth[root] = 0;
      return 0;
    }
    depth[root] = std::max(maxDepth(root->left), maxDepth(root->right)) + 1;
    return depth[root];
  }

  int findDiameterOfBinaryTree(TreeNode *root) {
    if (root == nullptr) {
      return 0;
    }
    int d = depth[root->left] + depth[root->right];
    d = std::max(findDiameterOfBinaryTree(root->left), d);
    d = std::max(findDiameterOfBinaryTree(root->right), d);
    return d;
  }
};
