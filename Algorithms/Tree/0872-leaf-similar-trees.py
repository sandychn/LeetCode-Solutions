# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def leafSimilar(self, root1: TreeNode, root2: TreeNode) -> bool:
        return self.getLeaves(root1) == self.getLeaves(root2)

    def getLeaves(self, root: TreeNode) -> List[TreeNode]:
        res = []

        def dfs(node: TreeNode):
            if not node:
                return
            if not node.left and not node.right:
                res.append(node.val)
            else:
                dfs(node.left)
                dfs(node.right)

        dfs(root)
        return res
