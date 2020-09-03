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
    vector<int> stk;
    vector<string> res;

    string getResultString() {
        string res = to_string(stk[0]);
        for (size_t i = 1, n = stk.size(); i < n; i++) {
            res += "->";
            res += to_string(stk[i]);
        }
        return res;
    }

    void dfs(TreeNode* root) {
        if (root == nullptr) {
            return;
        }
        stk.push_back(root->val);
        if (root->left == nullptr && root->right == nullptr) {
            res.push_back(getResultString());
        } else {
            dfs(root->left);
            dfs(root->right);
        }
        stk.pop_back();
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        res.clear();
        dfs(root);
        return res;
    }
};
