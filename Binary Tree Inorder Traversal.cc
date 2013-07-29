// Small: 8ms; Large: 16ms
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
  vector<int> inorderTraversal(TreeNode *root) {
    vector<int> res;
    stack<TreeNode *> nodes;
    TreeNode *cur = root;
    while (cur || !nodes.empty()) {
      if (cur) {
        nodes.push(cur);
        cur = cur->left;
      } else {
        cur = nodes.top();
        nodes.pop();
        res.push_back(cur->val);
        cur = cur->right;
      }
    }
    return res;
  }
};
