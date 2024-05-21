/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    public boolean isBalanced(TreeNode root) {
        int height = getHeight(root);
        return (height != -1);
    }

    private int getHeight(TreeNode root) {
        if (root == null) return 0;
        int leftHeight = root.left == null ? 0 : getHeight(root.left);
        int rightHeight = root.right == null ? 0 : getHeight(root.right);
        if (leftHeight == -1 || rightHeight == -1) return -1;
        else if (Math.abs(leftHeight - rightHeight) > 1) return -1;
        else return Math.max(leftHeight, rightHeight) + 1;
    }
}