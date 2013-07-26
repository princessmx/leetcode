// Small: 12ms; Large: 60ms
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
  bool hasPathSum(TreeNode *root, int sum) {
    sum_ = sum;
    dfs(root, 0);
  }
 private:
  bool dfs(TreeNode *node, int path_sum) {
    if (!node) {
      return false;
    }
    int sum = path_sum + node->val;
    if (!node->left && !node->right) {
      if (sum  == sum_) {
        return true;
      }
    } else {
      if (dfs(node->left, sum) || dfs(node->right, sum)) {
        return true;
      }
    }
    return false;
  }
  int sum_;
};
