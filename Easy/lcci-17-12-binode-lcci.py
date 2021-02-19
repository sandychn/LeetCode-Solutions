# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def convertBiNode(self, root: TreeNode) -> TreeNode:
        self.root = self.leaf = TreeNode()
        self.inorderTraverse(root)
        return self.root.right
    
    def inorderTraverse(self, root: TreeNode) -> None:
        if not root: return
        self.inorderTraverse(root.left)
        self.leaf.right = root
        self.leaf = root
        root.left = None
        self.inorderTraverse(root.right)
