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
private:
    vector<int> numbers;
    int count;
    int currentNumber;
    int currentCount;

public:
    vector<int> findMode(TreeNode* root) {
        numbers.clear();
        count = currentCount = 0;
        solve(root);
        return numbers;
    }

    void solve(TreeNode* root) {
        if (root == nullptr) return;

        solve(root->left);

        if (root->val == currentNumber) {
            ++currentCount;
        } else {
            currentNumber = root->val, currentCount = 1;
        }
        updateAnswer(root->val);

        solve(root->right);
    }

    inline void updateAnswer(int val) {
        if (currentCount > count) {
            numbers.clear();
            numbers.push_back(val);
            count = currentCount;
        } else if (currentCount == count) {
            numbers.push_back(val);
        }
    }
};
