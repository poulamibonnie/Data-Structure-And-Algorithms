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
    int helper(TreeNode* root, bool &isBal) {
        if(!root || !isBal) {
            return 0;
        }
        int left = helper(root->left, isBal);
        int right = helper(root->right, isBal);
        if (abs(left - right) > 1) {
            isBal = false;
            return 0;
        }
        return 1 + max(left, right);
        
    }
    bool isBalanced(TreeNode* root) {
        if (!root) {
            return true;
        }
        bool isBal = true;
        helper(root, isBal);
        return isBal;
    }
};
