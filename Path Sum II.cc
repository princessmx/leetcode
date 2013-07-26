// Small: 12ms; Large: 68ms
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
  vector<vector<int> > pathSum(TreeNode *root, int sum) {
    sum_ = sum;
    paths_.clear();
    vector<int> path;
    int path_sum = 0;
    dfs(root, path_sum, &path);
    return paths_;
  }
 private:
  void dfs(TreeNode *node, int sum, vector<int>* path) {
    if (!node) return;
    path->push_back(node->val);
    if (!node->left && !node->right) {
      if (sum + node->val == sum_) {
        paths_.push_back(*path);
      }
    } else {
      dfs(node->left, sum + node->val, path);
      dfs(node->right, sum + node->val, path);
    }
    path->pop_back();
  }

  int sum_;
  vector<vector<int> > paths_;
};
