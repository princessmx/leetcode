// Small: 4ms; Large: 20ms
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
  int sumNumbers(TreeNode *root) {
    vector<int> path;
    int sum = 0;
    traverse(root, &path, &sum);
    return sum;
  }
 private:
  void traverse(TreeNode *node, vector<int> *path, int *sum) {
    if (!node) {
      return;
    }
    path->push_back(node->val);
    if (!node->left && !node->right) {
      int val = 0;
      for (int i = 0; i < path->size(); i++) {
        val = val * 10 + (*path)[i];
      }
      *sum += val;
    }
    traverse(node->left, path, sum);
    traverse(node->right, path, sum);
    path->pop_back();
  }
};
