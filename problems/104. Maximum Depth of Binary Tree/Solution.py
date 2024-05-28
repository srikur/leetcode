# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def maxDepth(self, root: Optional[TreeNode]) -> int:
        return self.getHeight(0, root)

    def getHeight(self, height: int, root: Optional[TreeNode]) -> int:
        if not root: return 0
        left = self.getHeight(height, root.left) if root.left else 0
        right = self.getHeight(height, root.right) if root.right else 0
        return max(left, right) + 1