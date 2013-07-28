// Small: 12ms; Large: 52ms
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
 public:
  int maxDepth(TreeNode *root) {
    max_depth_ = 0;
    dfs(root, 0);
    return max_depth_;
  }
 private:
  void dfs(TreeNode *node, int depth) {
    if (!node) {
      return;
    }
    depth++;
    if (!node->left && !node->right) {
      max_depth_ = depth > max_depth_ ? depth : max_depth_;
      return;
    }
    dfs(node->left, depth);
    dfs(node->right, depth);
  }
  int max_depth_;
};
