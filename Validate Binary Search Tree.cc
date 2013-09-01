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
  bool isValidBST(TreeNode *root) {
    return isValidBST(root, INT_MIN, INT_MAX);
  }
 private:
  bool isValidBST(TreeNode *root, int min_val, int max_val) {
    if (!root) {
      return true;
    }
    if (root->val >= max_val || root->val <= min_val) {
      return false;
    }
    return isValidBST(root->left, min_val, root->val) &&
           isValidBST(root->right, root->val, max_val);
  }
};
