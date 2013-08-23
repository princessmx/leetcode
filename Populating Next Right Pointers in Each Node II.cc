// Small: 12ms; Large: 168ms
/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
 public:
  void connect(TreeLinkNode *root) {
    TreeLinkNode *parent = root, *first, *last;
    while (parent) {
      first = last = NULL;
      while (parent) {
        if (parent->left) {
          if (!first) {
            first = parent->left;
            last = first;
          } else {
            last->next = parent->left;
            last = last->next;
          }
        }
        if (parent->right) {
          if (!first) {
            first = parent->right;
            last = first;
          } else {
            last->next = parent->right;
            last = last->next;
          }
        }
        parent = parent->next;
      }
      parent = first;
    }
  }
};
