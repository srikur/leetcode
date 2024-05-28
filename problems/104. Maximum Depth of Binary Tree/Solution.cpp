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
    int maxDepth(TreeNode* root) {
        return getHeight(0, root);
    }

    int getHeight(int height, TreeNode* root) {
        if (!root) return 0;
        int left = root->left ? getHeight(height, root->left) : 0;
        int right = root->right ? getHeight(height, root->right) : 0;
        return std::max(left, right) + 1;
    }
};