# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    maxDiameter = 0

    def diameterOfBinaryTree(self, root: Optional[TreeNode]) -> int:
        self.getDiameter(0, root)
        return self.maxDiameter
    
    def getDiameter(self, diameter: int, root: Optional[TreeNode]) -> int:
        if not root: return 0
        left = self.getDiameter(diameter, root.left)
        right = self.getDiameter(diameter, root.right)
        self.maxDiameter = max(self.maxDiameter, left + right)
        return max(left, right) + 1