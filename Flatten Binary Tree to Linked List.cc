// Small: 8ms; Large: 48ms
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
  void flatten(TreeNode *root) {
    TreeNode *dump;
    preOrderFlatten(root, &dump);
  }
 private:
  void preOrderFlatten(TreeNode *node, TreeNode **last) {
    if (!node) {
      return;
    }
    *last = node;
    if (node->left) {
      preOrderFlatten(node->left, last);
    }
    TreeNode *right_last = NULL;
    if (node->right) {
      preOrderFlatten(node->right, &right_last);
    }
    if (*last != node) {
      (*last)->right = node->right;
      node->right = node->left;
      node->left = NULL;
    }
    if (right_last) {
      *last = right_last;
    }
  }
};
