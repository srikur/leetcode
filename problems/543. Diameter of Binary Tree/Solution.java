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
    private int maxDiameter;

    public int diameterOfBinaryTree(TreeNode root) {
        getDiameter(0, root);
        return maxDiameter;
    }

    private int getDiameter(int diameter, TreeNode root) {
        // My diameter is the max(leftDiameter, rightDiameter, leftHeight + rightHeight + 2)
        if (root == null) return 0;
        int leftDiameter = getDiameter(diameter, root.left);
        int rightDiameter = getDiameter(diameter, root.right);
        maxDiameter = Math.max(maxDiameter, leftDiameter + rightDiameter);
        return Math.max(leftDiameter, rightDiameter) + 1;
    }
}