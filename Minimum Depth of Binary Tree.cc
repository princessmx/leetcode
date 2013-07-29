// Small: 12ms; Large: 56ms
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
  int minDepth(TreeNode *root) {
    if (!root) {
      return 0;
    }
    queue<NodeWithLevel> nodes;
    nodes.push(NodeWithLevel(root, 1));
    while (!nodes.empty()) {
      NodeWithLevel node = nodes.front();
      if (!node.tree_node->left && !node.tree_node->right) {
        return node.level;
      }
      if (node.tree_node->left) {
        nodes.push(NodeWithLevel(node.tree_node->left, node.level + 1));
      }
      if (node.tree_node->right) {
        nodes.push(NodeWithLevel(node.tree_node->right, node.level + 1));
      }
      nodes.pop();
    }
  }
 private:
  struct NodeWithLevel {
    NodeWithLevel(TreeNode *_tree_node, int _level)
        : tree_node(_tree_node), level(_level) {}

    TreeNode *tree_node;
    int level;
  };
};
