// Small: 8ms; Large: 64ms
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
  bool isBalanced(TreeNode *root) {
    int depth = 0;
    return isBalanced(root, &depth);
  }
 private:
  bool isBalanced(TreeNode *node, int *depth) {
    if (node) {
      int left_depth = 0;
      int right_depth = 0;
      if (!isBalanced(node->left, &left_depth) ||
          !isBalanced(node->right, &right_depth) ||
          abs(left_depth - right_depth) > 1) {
        return false;
      }
      *depth = max(left_depth, right_depth) + 1;
      return true;
    }
    *depth = 0;
    return true;
  }
};
