# """
# This is the interface that allows for creating nested lists.
# You should not implement it, or speculate about its implementation
# """
#class NestedInteger:
#    def isInteger(self) -> bool:
#        """
#        @return True if this NestedInteger holds a single integer, rather than a nested list.
#        """
#
#    def getInteger(self) -> int:
#        """
#        @return the single integer that this NestedInteger holds, if it holds a single integer
#        Return None if this NestedInteger holds a nested list
#        """
#
#    def getList(self) -> [NestedInteger]:
#        """
#        @return the nested list that this NestedInteger holds, if it holds a nested list
#        Return None if this NestedInteger holds a single integer
#        """

from typing import List


class StackNode:
    def __init__(self, lst: List[NestedInteger], idx: int):
        self.lst = lst
        self.idx = idx


class NestedIterator:
    def __init__(self, nestedList: List[NestedInteger]):
        self.stack = [StackNode(nestedList, 0)]
    
    def next(self) -> int:
        return self.next_value

    def process(self) -> None:
        while self.stack:
            node = self.stack[-1]
            if node.idx >= len(node.lst):
                self.stack.pop()
                continue
            if node.lst[node.idx].isInteger():
                self.next_value = node.lst[node.idx].getInteger()
                node.idx += 1
                return
            lst = node.lst[node.idx].getList()
            node.idx += 1
            self.stack.append(StackNode(lst, 0))

    def hasNext(self) -> bool:
        self.process()
        return bool(self.stack)

# Your NestedIterator object will be instantiated and called as such:
# i, v = NestedIterator(nestedList), []
# while i.hasNext(): v.append(i.next())
