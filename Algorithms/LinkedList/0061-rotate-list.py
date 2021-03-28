# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def rotateRight(self, head: ListNode, k: int) -> ListNode:
        length = self.getListLength(head)
        if length == 0 or k % length == 0:
            return head
        k %= length
        slow = fast = head
        for _ in range(k):
            fast = fast.next
        while fast.next is not None:
            slow = slow.next
            fast = fast.next
        fast.next = head
        res = slow.next
        slow.next = None
        return res

    def getListLength(self, head: ListNode) -> int:
        length = 0
        while head:
            length += 1
            head = head.next
        return length
