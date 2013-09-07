// Small: 16ms; Large: 312ms
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
    void recoverTree(TreeNode *root) {
        TreeNode *prev = NULL, *first = NULL, *second;
        getMistakenNode(root, &prev, &first, &second);
        swap(first->val, second->val);
    }
private:
    void getMistakenNode(TreeNode *node,
                         TreeNode **prev,
                         TreeNode **first,
                         TreeNode **second) {
        if (!node) {
            return;
        }
        getMistakenNode(node->left, prev, first, second);
        if (*prev) {
            if ((*prev)->val > node->val) {
                if (!*first) {
                    *first = *prev;
                }
                *second = node;
            }
        }
        *prev = node;
        getMistakenNode(node->right, prev, first, second);
    }
};
