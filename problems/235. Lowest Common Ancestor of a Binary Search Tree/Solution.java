/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */

class Solution {
    private int lowerBound = 0;
    private int upperBound = 0;

    public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
        lowerBound = Math.min(p.val, q.val);
        upperBound = Math.max(p.val, q.val);
        int height = getHeight(root);
        for (int i = 1; i <= height; i++) {
            TreeNode lca = levelOrder(i, root);
            if (lca != null) return lca;
        }
        return null;
    }

    private int getHeight(TreeNode root) {
        if (root == null) return 0;
        int leftHeight = (root.left == null) ? 0 : getHeight(root.left);
        int rightHeight = (root.right == null) ? 0 : getHeight(root.right);
        return Math.max(leftHeight, rightHeight) + 1;
    }

    private TreeNode levelOrder(int height, TreeNode root) {
        if (root == null) return null;
        if (height == 1 && root.val >= lowerBound && root.val <= upperBound) {
            return root;
        } else {
            TreeNode left = levelOrder(height - 1, root.left);
            TreeNode right = levelOrder(height - 1, root.right);
            if (left != null || right != null) return left == null ? right : left;
            else return null;
        }
    }
}