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
public:
    bool isBalanced(TreeNode* root) {
        int height = getHeight(root);
        return (height != -1);
    }

    int getHeight(TreeNode* root) {
        if (!root) return 0;
        int leftHeight = root->left ? getHeight(root->left) : 0;
        int rightHeight = root->right ? getHeight(root->right) : 0;
        if (leftHeight == -1 || rightHeight == -1) return -1;
        else if (std::abs(getHeight(root->left) - getHeight(root->right)) > 1) return -1;
        else return max(leftHeight, rightHeight) + 1;
    }
};