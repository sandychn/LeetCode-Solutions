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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if (root == nullptr) {
            return {};
        }
        vector<vector<int>> res;
        queue<TreeNode*> q;
        q.push(root);
        for (int i = 0; !q.empty(); i++) {
            vector<int> thisLevel;
            int size = q.size();
            while (size--) {
                TreeNode* now = q.front();
                q.pop();
                thisLevel.push_back(now->val);
                if (now->left) q.push(now->left);
                if (now->right) q.push(now->right);
            }
            res.push_back(move(thisLevel));
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
