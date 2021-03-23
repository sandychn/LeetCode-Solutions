# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def findTilt(self, root: TreeNode) -> int:
        self.ans = 0
        self.dfs(root)
        return self.ans

    def dfs(self, root: TreeNode) -> int:
        if root:
            left = self.dfs(root.left)
            right = self.dfs(root.right)
            self.ans += abs(left - right)
            return left + right + root.val
        return 0
