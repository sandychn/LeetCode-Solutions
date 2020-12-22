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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (!root) return {};
        
        queue<TreeNode*> q;
        q.push(root);

        vector<vector<int>> res;
        while (!q.empty()) {
            vector<int> level;
            for (int i = 0, n = q.size(); i < n; i++) {
                TreeNode* now = q.front();
                q.pop();
                level.push_back(now->val);
                if (now->left) q.push(now->left);
                if (now->right) q.push(now->right);
            }
            if (res.size() & 1) reverse(begin(level), end(level));
            res.push_back(move(level));
        }
        return res;
    }
};
