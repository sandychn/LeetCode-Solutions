# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def findSecondMinimumValue(self, root: TreeNode) -> int:
        self.ans = None
        self.minValue = root.val
        self.dfs(root)
        return self.ans if self.ans is not None else -1

    def dfs(self, root):
        if not root:
            return
        if root.val > self.minValue:  # every value in root and its subtree is <= root.val
            self.ans = root.val if self.ans is None else min(self.ans, root.val)
        else:
            self.dfs(root.left)
            self.dfs(root.right)
