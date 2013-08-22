// Small: 8ms; Large: 92ms
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
  TreeNode *sortedArrayToBST(vector<int> &num) {
    return sortedArrayToBST(num, 0, num.size());
  }
 private:
  TreeNode* sortedArrayToBST(vector<int> &num, int l, int r) {
    if (l >= r) {
      return NULL;
    }
    int m = (l + r) >> 1;
    TreeNode* root = new TreeNode(num[m]);
    root->left = sortedArrayToBST(num, l, m);
    root->right = sortedArrayToBST(num, m + 1, r);
  }
};
