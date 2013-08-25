// Small: 8ms; Large: 88ms
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
 public:
  TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
    for (int i = 0; i < inorder.size(); i++) {
      inorder_index_map_[inorder[i]] = i;
    }
    return buildTree(preorder, 0, preorder.size(), inorder, 0, inorder.size());
  }
 private:
  TreeNode *buildTree(vector<int> &preorder,
                      int pre_l,
                      int pre_r,
                      vector<int> &inorder,
                      int in_l,
                      int in_r) {
    if (pre_l >= pre_r) {
      return NULL;
    }
    TreeNode *node = new TreeNode(preorder[pre_l]);
    int n_index = inorder_index_map_[preorder[pre_l]];
    int left_sz = n_index - in_l;
    int pre_left_end = pre_l + left_sz + 1;
    node->left = buildTree(preorder, pre_l + 1, pre_left_end, inorder, in_l, n_index);
    node->right = buildTree(preorder, pre_left_end, pre_r, inorder, n_index + 1, in_r);
    return node;
  }
  map<int, int> inorder_index_map_;
};
