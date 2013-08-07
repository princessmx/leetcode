// Small: 8ms; Large: 24ms
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
  vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
    vector<vector<int> > res;
    stack<TreeNode *> stack1, stack2;
    if (root) {
      stack1.push(root);
      res.push_back(vector<int>());
    }
    Direction direction = LEFT_TO_RIGHT;
    while (!stack1.empty() || !stack2.empty()) {
      switch (direction) {
        case LEFT_TO_RIGHT:
          if (!stack1.empty()) {
            TreeNode *node = stack1.top();
            stack1.pop();
            vector<int> &last = res.back();
            last.push_back(node->val);
            if (node->left) {
              stack2.push(node->left);
            }
            if (node->right) {
              stack2.push(node->right);
            }
          } else if (!stack2.empty()) {
            res.push_back(vector<int>());
            direction = RIGHT_TO_LEFT;
          }
          break;
        case RIGHT_TO_LEFT:
          if (!stack2.empty()) {
            TreeNode *node = stack2.top();
            stack2.pop();
            vector<int> &last = res.back();
            last.push_back(node->val);
            if (node->right) {
              stack1.push(node->right);
            }
            if (node->left) {
              stack1.push(node->left);
            }
          } else if (!stack1.empty()) {
            res.push_back(vector<int>());
            direction = LEFT_TO_RIGHT;
          }
          break;
      }
    }
    return res;
  }
 private:
  enum Direction {
    LEFT_TO_RIGHT = 0,
    RIGHT_TO_LEFT,
  };
};
