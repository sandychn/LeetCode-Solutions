# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def rangeSumBST(self, root: TreeNode, low: int, high: int) -> int:
        return self.inorder(root, low, high)

    def inorder(self, root: TreeNode, low: int, high: int) -> int:
        if not root:
            return 0
        ans = 0
        if low <= root.val <= high:
            ans += root.val
        if root.val >= low:
            ans += self.inorder(root.left, low, high)
        if root.val <= high:
            ans += self.inorder(root.right, low, high)
        return ans
