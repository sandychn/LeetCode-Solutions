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
    struct Result {
        int robHere;
        int notRobHere;
    };

    int rob(TreeNode* root) {
        auto res = f(root);
        return max(res.robHere, res.notRobHere);
    }
    
    Result f(TreeNode* root) {
        if (root == nullptr) {
            return {0, 0};
        }
        auto left = f(root->left);
        auto right = f(root->right);
        return {
            root->val + left.notRobHere + right.notRobHere,
            max(left.robHere, left.notRobHere) + max(right.robHere, right.notRobHere)
        };
    }
};

class _Solution {
public:
    unordered_map<TreeNode*, int> mem[2];

    int rob(TreeNode* root) {
        return f(root, false);
    }

    int f(TreeNode* root, bool isFatherRobbed) {
        if (root == nullptr) {
            return 0;
        }
        if (mem[int(isFatherRobbed)].count(root)) {
            return mem[int(isFatherRobbed)][root];
        }
        int res = 0;
        res = max(res, f(root->left, false) + f(root->right, false));
        if (!isFatherRobbed) {
            res = max(res, root->val + f(root->left, true) + f(root->right, true));
        }
        return mem[int(isFatherRobbed)][root] = res;
    }
};
