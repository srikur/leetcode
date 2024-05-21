# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    lowerBound = None
    upperBound = None

    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        self.lowerBound, self.upperBound = min(p.val, q.val), max(p.val, q.val)
        height = self.getHeight(root)
        lca = None
        for i in range(1, height + 1):
            lca = self.levelOrder(i, root)
            if lca != None: return lca
        return None

    def getHeight(self, root: 'TreeNode') -> int:
        if not root: return 0
        leftHeight = 0 if root.left == None else self.getHeight(root.left)
        rightHeight = 0 if root.right == None else self.getHeight(root.right)
        return max(leftHeight, rightHeight) + 1

    def levelOrder(self, height: int, root: 'TreeNode') -> Optional[TreeNode]:
        if not root: return None
        if (height == 1) and (root.val >= self.lowerBound) and (root.val <= self.upperBound):
            return root
        else:
            leftRet = self.levelOrder(height - 1, root.left)
            rightRet = self.levelOrder(height - 1, root.right)
            if leftRet or rightRet: return leftRet if leftRet else rightRet
            else: return None
        