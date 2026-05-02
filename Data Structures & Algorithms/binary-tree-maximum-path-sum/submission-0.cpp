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
    int helper(TreeNode* root, int &maxPath) {
        if (!root) {
            return 0;
        }
        int left = max(0, helper(root->left, maxPath));
        int right = max(0, helper(root->right, maxPath));
        maxPath = max(maxPath, root->val + left + right);
        return root->val + max(left, right);
    }
    int maxPathSum(TreeNode* root) {
        int maxPath = INT_MIN;
        helper(root, maxPath);
        return maxPath;
    }
};
