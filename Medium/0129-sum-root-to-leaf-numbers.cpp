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
    int sumNumbers(TreeNode* root) {
        ans = 0;
        traverse(root, 0);
        return ans;
    }

private:
    int ans;

    void traverse(TreeNode* node, int v) {
        if (node == nullptr) return;
        v = v * 10 + node->val;
        if (node->left == nullptr && node->right == nullptr) {
            ans += v;
            return;
        }
        traverse(node->left, v);
        traverse(node->right, v);
    }
};
