// Small: 12ms; Large: 136ms
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
  int maxPathSum(TreeNode *root) {
    max_path_ = INT_MIN;
    int dummy;
    computePathSum(root, &dummy);
    return max_path_;
  }
 private:
  void computePathSum(TreeNode *node, int *max_to_root) {
    if (!node) {
      return;
    }
    int max_left = 0, max_right = 0;
    if (node->left) {
      computePathSum(node->left, &max_left);
    }
    if (node->right) {
      computePathSum(node->right, &max_right);
    }
    int max_sub_tree = max(max_left, max_right);
    *max_to_root = max_sub_tree > 0 ? max_sub_tree + node->val : node->val;
    if (max_path_ < *max_to_root) {
      max_path_ = *max_to_root;
    }
    int max_pass_node = node->val;
    if (max_left > 0) {
      max_pass_node += max_left;
    }
    if (max_right > 0) {
      max_pass_node += max_right;
    }
    if (max_path_ < max_pass_node) {
      max_path_ = max_pass_node;
    }
  }
  int max_path_;
};
