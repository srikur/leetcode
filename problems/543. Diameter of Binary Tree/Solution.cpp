/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    int maxDiameter = 0;

public:
    int diameterOfBinaryTree(TreeNode* root) {
        getDiameter(0, root);
        return maxDiameter;
    }

    int getDiameter(int diameter, TreeNode* root) {
        if (!root) return 0;
        int leftDiameter = getDiameter(diameter, root->left);
        int rightDiameter = getDiameter(diameter, root->right);
        maxDiameter = std::max(maxDiameter, leftDiameter + rightDiameter);
        return std::max(leftDiameter, rightDiameter) + 1;
    }
};