# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class StackNode:
    def __init__(self, root: TreeNode, status: int):
        self.node = root
        self.stat = status


class BSTIterator:
    def __init__(self, root: TreeNode):
        self.stack = [StackNode(root, 0)]
        self.element = None
        self.moveNext()

    def next(self) -> int:
        e = self.element
        self.moveNext()
        return e

    def hasNext(self) -> bool:
        return self.element is not None

    def moveNext(self) -> None:
        stack = self.stack
        while stack:
            top = stack[-1]
            if top.node is None:
                stack.pop()
            elif top.stat == 0:
                stack.append(StackNode(top.node.left, 0))
                top.stat += 1
            elif top.stat == 1:
                self.element = top.node.val
                top.stat += 1
                return
            elif top.stat == 2:
                stack.append(StackNode(top.node.right, 0))
                top.stat += 1
            elif top.stat == 3:
                stack.pop()
        self.element = None

# Your BSTIterator object will be instantiated and called as such:
# obj = BSTIterator(root)
# param_1 = obj.next()
# param_2 = obj.hasNext()
