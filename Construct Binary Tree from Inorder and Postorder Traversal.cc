// Small: 16ms; Large: 76ms
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
  TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
    for (int i = 0; i < inorder.size(); i++) {
      inorder_index[inorder[i]] = i;
    }
    return buildTree(inorder, 0, inorder.size(), postorder, 0, postorder.size());
  }
 private:
  TreeNode *buildTree(vector<int> &inorder,
                      int in_l,
                      int in_r,
                      vector<int> &postorder,
                      int post_l,
                      int post_r) {
    if (in_l >= in_r) {
      return NULL;
    }
    TreeNode *node = new TreeNode(postorder[post_r - 1]);
    int n_index = inorder_index[postorder[post_r - 1]];
    int left_sz = n_index - in_l;
    int right_sz = in_r - n_index - 1;
    node->left = buildTree(inorder, in_l, in_l + left_sz, postorder, post_l, post_l + left_sz);
    node->right = buildTree(inorder, n_index + 1, in_r, postorder, post_r - right_sz - 1, post_r - 1);
    return node;
  }
  map<int, int> inorder_index;
};
