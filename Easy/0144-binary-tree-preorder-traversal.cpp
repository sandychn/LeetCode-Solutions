/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
 
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> stk;

        pushNotNull(stk, root);
        while (!stk.empty()) {
            TreeNode* node = stk.top();
            stk.pop();

            res.push_back(node->val);
            pushNotNull(stk, node->right);
            pushNotNull(stk, node->left);
        }

        return res;
    }

    static void pushNotNull(stack<TreeNode*>& stk, TreeNode* node) {
        node ? stk.push(node) : void();
    }
};
