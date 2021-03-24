# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def deleteDuplicates(self, head: ListNode) -> ListNode:
        last = dummy = ListNode()
        ignored = None
        while head:
            val = head.val
            if val == ignored:
                head = head.next
            else:
                ignored = None
                if head.next and head.next.val == val:
                    ignored = val
                    head = head.next
                else:
                    last.next = head
                    last = head
                    head = head.next
        last.next = None
        return dummy.next
