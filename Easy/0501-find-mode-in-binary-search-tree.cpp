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
    vector<int> findMode(TreeNode* root) {
        init();
        traverse(root);
        return res;
    }

private:
    vector<int> res;
    int maxOccurrence;
    int currentValue;
    int currentOccurrence;

    void init() {
        res.clear();
        maxOccurrence = 0;
        currentOccurrence = 0;
    }
    
    void traverse(TreeNode* node) {
        if (!node) return;

        traverse(node->left);

        int value = node->val;
        if (currentOccurrence == 0 || currentValue != value) {
            currentValue = value;
            currentOccurrence = 1;
        } else {  // currentValue == value
            ++currentOccurrence;
        }
        
        if (currentOccurrence == maxOccurrence) {
            res.push_back(currentValue);
        } else if (currentOccurrence > maxOccurrence) {
            maxOccurrence = currentOccurrence;
            res.clear();
            res.push_back(currentValue);
        }

        traverse(node->right);
    }
};
