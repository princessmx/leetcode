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
  bool isSymmetric(TreeNode *root) {
    if (!root) {
      return true;
    }
    vector<TreeNode *> nodes;
    nodes.push_back(root);
    int cur = 0, last = 1;
    while (cur < last) {
      if (!isSymmetric(nodes, cur, last)) {
        return false;
      }
      while (cur < last) {
        if (nodes[cur]) {
          nodes.push_back(nodes[cur]->left);
          nodes.push_back(nodes[cur]->right);
        }
        cur++;
      }
      last = nodes.size();
    }
    return true;
  }
 private:
  bool isSymmetric(const vector<TreeNode *> &nodes, int start, int end) {
    int half = (end - start) >> 1;
    for (int i = 0; i < half; i++) {
      int i1 = start + i, i2 = end - i - 1;
      if ((!nodes[i1] && !nodes[i2]) ||
          (nodes[i1] && nodes[i2] && nodes[i1]->val == nodes[i2]->val)) {
        continue;
      }
      return false;
    }
    return true;
  }
};
