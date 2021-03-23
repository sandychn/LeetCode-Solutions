"""
# Definition for a Node.
class Node:
    def __init__(self, val=None, children=None):
        self.val = val
        self.children = children
"""

class StackNode:
    def __init__(self, node: 'Node', idx: int) -> None:
        self.node = node
        self.idx = idx


class Solution:
    def preorder(self, root: 'Node') -> List[int]:
        stack = [StackNode(root, -1)]
        res = []
        while stack:
            top = stack[-1]
            if top.node:
                if top.idx == -1:
                    res.append(top.node.val)
                    top.idx += 1
                elif top.idx < len(top.node.children):
                    stack.append(StackNode(top.node.children[top.idx], -1))
                    top.idx += 1
                else:
                    stack.pop()
            else:
                stack.pop()
        return res
