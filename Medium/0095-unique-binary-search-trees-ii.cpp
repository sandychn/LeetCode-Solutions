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
    vector<TreeNode*> generate(int l, int r) {
        vector<TreeNode*> res;
        for (int root = l; root <= r; root++) {
            vector<TreeNode*> resLeft = generate(l, root - 1);
            vector<TreeNode*> resRight = generate(root + 1, r);
            if (resLeft.empty()) {
                resLeft.push_back(nullptr);
            }
            if (resRight.empty()) {
                resRight.push_back(nullptr);
            }
            for (TreeNode* ansLeft : resLeft) {
                for (TreeNode* ansRight : resRight) {
                    res.push_back(new TreeNode(root, ansLeft, ansRight));
                }
            }
        }
        return res;
    }

    vector<TreeNode*> generateTrees(int n) {
        return generate(1, n);
    }
};
