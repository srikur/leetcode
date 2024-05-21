# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isBalanced(self, root: Optional[TreeNode]) -> bool:
        height = self.getHeight(root)
        return height != -1

    def getHeight(self, root: Optional[TreeNode]) -> int:
        if not root: return 0
        leftHeight = 0 if root.left == None else self.getHeight(root.left)
        rightHeight = 0 if root.right == None else self.getHeight(root.right)
        if (leftHeight == -1) or (rightHeight == -1): return -1
        elif (abs(leftHeight - rightHeight) > 1): return -1
        else: return max(leftHeight, rightHeight) + 1