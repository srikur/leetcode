/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
private:
    int lowerBound;
    int upperBound;

public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        lowerBound = std::min(p->val, q->val);
        upperBound = std::max(p->val, q->val);
        int height = getHeight(root);
        for (int i = 1; i <= height; i++) {
            TreeNode* lca = levelOrder(i, root);
            if (lca) return lca;
        }
        return nullptr;
    }

    int getHeight(TreeNode* root) {
        if (!root) return 0;
        int leftHeight = root->left ? getHeight(root->left) : 0;
        int rightHeight = root->right ? getHeight(root->right) : 0;
        return std::max(leftHeight, rightHeight) + 1;
    }

    TreeNode* levelOrder(int height, TreeNode* root) {
        if (!root) return nullptr;
        if (height == 1 && root->val >= lowerBound && root->val <= upperBound) {
            return root;
        } else {
            TreeNode* left = levelOrder(height - 1, root->left);
            TreeNode* right = levelOrder(height - 1, root->right);
            if (left || right) return left ? left : right;
            else return nullptr;
        }
    }
};