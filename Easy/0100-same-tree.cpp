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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (p && q) {
            return p->val == q->val && isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
        }
        return !p && !q;
    }
};

class _Solution {
   public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        queue<TreeNode*> pQueue, qQueue;
        pQueue.push(p);
        qQueue.push(q);
        while (!pQueue.empty() && !qQueue.empty()) {
            TreeNode* pFront = pQueue.front();
            TreeNode* qFront = qQueue.front();

            pQueue.pop();
            qQueue.pop();

            if (pFront == nullptr || qFront == nullptr) {
                if (!(pFront == nullptr && qFront == nullptr)) {
                    return false;
                }
            } else if (pFront->val != qFront->val) {
                return false;
            } else {
                pQueue.push(pFront->left);
                pQueue.push(pFront->right);
                qQueue.push(qFront->left);
                qQueue.push(qFront->right);
            }
        }
        return pQueue.empty() && qQueue.empty();
    }
};
