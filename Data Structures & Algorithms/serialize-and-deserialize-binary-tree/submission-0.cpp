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

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (!root) {
            return "N ";
        }

        queue<TreeNode *> q;
        q.push(root);
        string tree = "";

        while (!q.empty()) {
            auto temp = q.front();
            q.pop();
            if (!temp) {
                tree += "N ";
            }
            else {
                tree += to_string(temp->val) + " ";
                q.push(temp->left);
                q.push(temp->right);
            }
        }

        return tree;
    }

    TreeNode * createNode(string &s) {
        if (s == "N") {
            return nullptr;
        }
        else {
            TreeNode * newNode = new TreeNode(stoi(s));
            return newNode;
        }
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        stringstream ss(data);
        string token;
        ss >> token;
        queue<TreeNode*> q;

        auto root = createNode(token);

        if (!root) {
            return nullptr;
        }
        q.push(root);

        while(!q.empty()) {
            auto temp = q.front();
            q.pop();

            ss >> token;
            temp->left = createNode(token);

            ss >> token;
            temp->right = createNode(token);

            if (temp->left) q.push(temp->left);
            if (temp->right) q.push(temp->right);
        }

        return root;
    }
};
