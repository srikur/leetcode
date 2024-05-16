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
    bool evaluateTree(TreeNode* root) {
        // Post order traversal: left, right, node
        if (!root->left && !root->right) return root->val;
        int leftVal = evaluateTree(root->left);
        int rightVal = evaluateTree(root->right);
        return (root->val == 2) ? /* OR */ leftVal || rightVal : /* AND */ leftVal && rightVal;
    }
};