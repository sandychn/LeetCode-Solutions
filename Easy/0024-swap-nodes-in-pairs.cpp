/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        ListNode* p = head;
        ListNode* res = p->next;
        while (p && p->next) {
            ListNode* q = p->next->next;
            p->next->next = p;
            if (q == nullptr) { // 2 elements left
                p->next = nullptr;
            } else if (q->next == nullptr) { // 3 elements left
                p->next = q;
            } else { // 4 or more elements left
                p->next = q->next;
            }
            p = q;
        }
        return res;
    }
};

class DummyNodeSolution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode dummy(0);
        ListNode* pre = &dummy;
        pre->next = head;
        
        while (head && head->next) {
            pre->next = head->next;
            ListNode* second = head->next;            
            head->next = second->next;
            second->next = head;

            pre = head;
            head = head->next;
        }

        return dummy.next;
    }
};
