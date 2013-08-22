// Small: 12ms; Large: 160ms
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
  TreeNode *sortedListToBST(ListNode *head) {
    ListNode *p = head;
    vector<int> sorted_vec;
    while (p) {
      sorted_vec.push_back(p->val);
      p = p->next;
    }
    return sortedListToBST(sorted_vec, 0, sorted_vec.size());
  }
 private:
  TreeNode *sortedListToBST(const vector<int> &vec, int l, int r) {
    if (l >= r) {
      return NULL;
    }
    int m = (l + r) >> 1;
    TreeNode *root = new TreeNode(vec[m]);
    root->left = sortedListToBST(vec, l, m);
    root->right = sortedListToBST(vec, m + 1, r);
  }
};
