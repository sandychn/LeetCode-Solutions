# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reverseBetween(self, head: ListNode, left: int, right: int) -> ListNode:
        prev, leftNode = None, head
        for _ in range(1, left):
            prev, leftNode = leftNode, leftNode.next
        node = leftNode
        last = None
        for _ in range(right - left + 1):
            next_node = node.next
            if prev:
                node.next = prev.next
                prev.next = node
            else:
                node.next = head
                head = node
            if not last:
                last = node
            node = next_node
        last.next = next_node
        return head
