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
    vector<TreeNode *> generateTrees(int n) {
        vector<TreeNode *> res;
        generateTrees(1, n, &res);
        return res;
    }
    private:
    void generateTrees(int l, int r, vector<TreeNode *>* trees) {
        if (l > r) {
            trees->push_back(NULL);
            return;
        }
        for (int i = l; i <= r; i++) {
            vector<TreeNode *> left, right;
            generateTrees(l, i - 1, &left);
            generateTrees(i + 1, r, &right);
            for (int j = 0; j < left.size(); j++) {
                for (int k = 0; k < right.size(); k++) {
                    TreeNode *n = new TreeNode(i);
                    n->left = left[j];
                    n->right = right[k];
                    trees->push_back(n);
                }
            }
        }
    }
};
