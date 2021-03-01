# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def mergeTrees(self, root1: TreeNode, root2: TreeNode) -> TreeNode:
        stack = []
        ans = None
        if root1 or root2:
            ans = TreeNode()
            stack.append((root1, root2, ans))
        while stack:
            r1, r2, rn = stack.pop()
            rn.val = (r1.val if r1 else 0) + (r2.val if r2 else 0)
            r1Left, r1Right = (r1.left, r1.right) if r1 else (None, None)
            r2Left, r2Right = (r2.left, r2.right) if r2 else (None, None)
            if r1Left or r2Left:
                rn.left = TreeNode()
                stack.append((r1Left, r2Left, rn.left))
            if r1Right or r2Right:
                rn.right = TreeNode()
                stack.append((r1Right, r2Right, rn.right))
        return ans
