/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* helper(Node* node, unordered_map<Node*, Node*> &deepCopy) {
        if (deepCopy.count(node)) {
            return deepCopy[node];
        }
        Node * newNode = new Node(node->val);
        deepCopy[node] = newNode;
        for (auto child : node->neighbors) {
            newNode->neighbors.push_back(helper(child, deepCopy));
        }
        return newNode;
    }
    Node* cloneGraph(Node* node) {
        unordered_map<Node*, Node*> deepCopy;
        if (!node) {
            return nullptr;
        }

        return helper(node, deepCopy);
    }
};
