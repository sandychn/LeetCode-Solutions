/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int getMinimumDifference(TreeNode* root) {
        cnt = 0;
        res = INT_MAX;
        inorderTraverse(root);
        return res;
    }

    void inorderTraverse(TreeNode* p) {
        if (p) {
            inorderTraverse(p->left);
            if (cnt++) res = min(res, p->val - pre);
            pre = p->val;
            inorderTraverse(p->right);
        }
    }

private:
    int cnt, pre, res;
};
