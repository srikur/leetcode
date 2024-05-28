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
    public int maxDepth(TreeNode root) {
        return getHeight(0, root);
    }

    private int getHeight(int height, TreeNode root) {
        if (root == null) return 0;
        int left = root.left == null ? 0 : getHeight(height, root.left);
        int right = root.right == null ? 0 : getHeight(height, root.right);
        return Math.max(left, right) + 1;
    }
}