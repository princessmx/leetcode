// Small: 8ms; Large: 28ms
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
  vector<vector<int> > levelOrder(TreeNode *root) {
    vector<vector<int> > res;
    queue<pair<TreeNode *, int> > nodes;
    if (root) {
      nodes.push(make_pair(root, 0));
    }
    int cur_level = -1;
    while (!nodes.empty()) {
      pair<TreeNode *, int> node = nodes.front();
      nodes.pop();
      if (node.second != cur_level) {
        res.push_back(vector<int>());
        cur_level = node.second;
      }
      vector<int>& nodes_vec = res.back();
      nodes_vec.push_back(node.first->val);
      if (node.first->left) {
        nodes.push(make_pair(node.first->left, node.second + 1));
      }
      if (node.first->right) {
        nodes.push(make_pair(node.first->right, node.second + 1));
      }
    }
    return res;
  }
};
