# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def sumOfLeftLeaves(self, root: TreeNode) -> int:
        return self.solve(root, False)  # the root is not left leave

    def solve(self, root, isLeft) -> int:
        if not root:
            return 0
        if isLeft and not root.left and not root.right:
            return root.val
        return self.solve(root.left, True) + self.solve(root.right, False)
