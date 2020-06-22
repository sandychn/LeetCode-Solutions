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
    vector<int> inorderTraversal(TreeNode* root) {
        stack<pair<TreeNode*, bool>> st;
        vector<int> result;

        if (root != nullptr) {
            st.emplace(root, 0);
            while (!st.empty()) {
                auto top = st.top();
                st.pop();

                if (top.second) {
                    result.push_back(top.first->val);
                } else {
                    if (top.first->right != nullptr) {
                        st.emplace(top.first->right, false);
                    }
                    st.emplace(top.first, true);
                    if (top.first->left != nullptr) {
                        st.emplace(top.first->left, false);
                    }
                }
            }
        }
        
        return result;
    }
};

class OfficalSolution {
   public:
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> st;
        vector<int> result;

        TreeNode* p = root;

        while (p != nullptr || !st.empty()) {
            while (p != nullptr) {
                st.push(p);
                p = p->left;
            }
            p = st.top();
            st.pop();
            result.push_back(p->val);
            p = p->right;
        }
        
        return result;
    }
};
