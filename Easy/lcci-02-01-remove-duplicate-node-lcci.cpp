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
    ListNode* removeDuplicateNodes(ListNode* head) {
        if (!head) return head;

        bitset<20001> mp;
        
        ListNode dummy(0);
        ListNode* pre = &dummy;
        dummy.next = head;

        while (head) {
            int val = head->val;
            if (mp[val]) {
                pre->next = head->next;
            } else {
                mp[val] = true;
                pre = head;
            }
            head = head->next;
        }

        return dummy.next;
    }
};
