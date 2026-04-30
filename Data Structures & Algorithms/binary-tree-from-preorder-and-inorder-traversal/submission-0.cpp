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
    int curr = 0;
public:
    TreeNode* helper(vector<int>& preorder, unordered_map<int, int> &inorderDict, int s, int e) {
        if (s > e) {
            return nullptr;
        }
        int elm = preorder[curr++];
        TreeNode * root = new TreeNode(elm);
        root->left = helper(preorder, inorderDict, s, inorderDict[elm] - 1);
        root->right = helper(preorder, inorderDict, inorderDict[elm] + 1, e);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> inorderDict;
        int n =  inorder.size();

        for (int i = 0; i < inorder.size(); i++) {
            inorderDict[inorder[i]] = i;
        }

        return helper(preorder, inorderDict, 0, n - 1);
    }
};
