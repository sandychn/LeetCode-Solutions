/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if (!root) return nullptr;

        Node* leftmost = root;
        while (leftmost->left) {
            Node* now = leftmost;
            while (now) {
                now->left->next = now->right;
                now->right->next = now->next ? now->next->left : nullptr;
                now = now->next;
            }
            leftmost = leftmost->left;
        }
        return root;
    }
};
