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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* p1 = root;
        TreeNode* p2 = root;
        TreeNode* res = root;
        while (p1 == p2) {
            if (p1->val < p->val) {
                p1 = p1->right;
            } else if (p1->val > p->val) {
                p1 = p1->left;
            }
            
            if (p2->val < q->val) {
                p2 = p2->right;
            } else if (p2->val > q->val) {
                p2 = p2->left;
            }

            if (p1 == p2) res = p1;
        }
        return res;
    }
};
