// Small: 8ms; Large: 120ms
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
    TreeLinkNode *cur = root, *first, *last;
    while (cur && cur->left && cur->right) {
      first = cur;
      last = NULL;
      while (cur) {
        if (last) {
          last->next = cur->left;
        }
        cur->left->next = cur->right;
        last = cur->right;
        cur = cur->next;
      }
      cur = first->left;
    }
  }
};
