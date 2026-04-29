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
    void helper(TreeNode* root, int highestMarker, int &cnt) {
        if (!root) {
            return;
        }
        if (highestMarker <= root->val) {
            highestMarker = root->val;
            cnt++;
        }
        helper(root->left, highestMarker, cnt);
        helper(root->right, highestMarker, cnt);
    }
    int goodNodes(TreeNode* root) {
        int cnt = 0;
        helper(root, -1001, cnt);
        return cnt;
    }
};
