// Small: 8ms; Large: 32ms
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
  vector<vector<int> > levelOrderBottom(TreeNode *root) {
    vector<vector<int> > top_traversal;
    queue<pair<TreeNode *, int> > nodes;
    if (root) {
      nodes.push(make_pair(root, 0));
    }
    int cur_level = -1;
    while (!nodes.empty()) {
      pair<TreeNode *, int> node_level = nodes.front();
      nodes.pop();
      if (cur_level < node_level.second) {
        cur_level = node_level.second;
        top_traversal.push_back(vector<int>());
      }
      vector<int>& cur_level_nodes = top_traversal.back();
      TreeNode *node = node_level.first;
      cur_level_nodes.push_back(node->val);
      if (node->left) {
        nodes.push(make_pair(node->left, cur_level + 1));
      }
      if (node->right) {
        nodes.push(make_pair(node->right, cur_level + 1));
      }
    }
    vector<vector<int> > res(top_traversal.size());
    for (int i = 0; i < res.size(); i++) {
      res[i].swap(top_traversal[top_traversal.size() - i - 1]);
    }
    return res;
  }
};
