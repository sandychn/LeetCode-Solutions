# -*- coding:utf8 -*-

# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def partition(self, head, x):
        """
        :type head: ListNode
        :type x: int
        :rtype: ListNode
        """
        less_than_head = less_than_tail = ListNode(None)
        not_less_than_head = not_less_than_tail = ListNode(None)

        now = head
        nex = None
        while now:
            if now.val < x:
                less_than_tail.next = now
                less_than_tail = less_than_tail.next
            else:
                not_less_than_tail.next = now
                not_less_than_tail = not_less_than_tail.next
            nex = now.next
            now.next = None
            now = nex
        
        less_than_tail.next = not_less_than_head.next       
        return less_than_head.next
