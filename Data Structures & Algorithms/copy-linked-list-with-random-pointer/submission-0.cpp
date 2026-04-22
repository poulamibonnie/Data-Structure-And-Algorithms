/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) {
            return nullptr;
        }

        Node * curr = head;
        Node * nhead = nullptr;

        while (curr) {
            Node * newNode = new Node(curr->val);
            Node * temp = curr->next;
            curr->next = newNode;
            newNode->next = temp;
            curr = temp;
        }

        curr = head;

        while (curr) {
            Node * temp = curr->random;
            curr = curr->next;
            if (!temp) {
                curr->random = nullptr;
            }
            else {
                curr->random = temp->next;
            }
            curr = curr->next;
        }

        curr = head;

        while (curr) {
            Node * temp = curr->next;
            if (!nhead) {
                nhead = temp;
            }
            if (!temp) {
                curr->next = nullptr;
            }
            else {
                curr->next = temp->next;
            }
            curr = temp;
        }

        return nhead;
    }
};
