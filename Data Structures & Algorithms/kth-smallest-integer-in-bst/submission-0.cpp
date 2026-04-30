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
    int cnt = 0;
public:
    int kthSmallest(TreeNode* root, int k) {
       if (!root) {
            return 1e9;
       } 
       auto left = kthSmallest(root->left,k);
       cnt++;
       if (k == cnt) {
            return root->val;
       }
       auto right = kthSmallest(root->right,k);
       return (left == 1e9) ? right : left;
    }
};
