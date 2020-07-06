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
    bool hasPathSum(TreeNode* root, int sum) {
        if (root == nullptr) return false;
        queue<pair<TreeNode*, int>> q;
        q.emplace(root, root->val);
        while (!q.empty()) {
            auto now = q.front();
            q.pop();
            if (now.second == sum && now.first->left == nullptr && now.first->right == nullptr) {
                return true;
            }
            if (now.first->left) {
                q.emplace(now.first->left, now.second + now.first->left->val);
            }
            if (now.first->right) {
                q.emplace(now.first->right, now.second + now.first->right->val);
            }
        }
        return false;
    }
};
