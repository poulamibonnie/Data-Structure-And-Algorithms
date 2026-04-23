/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
    ListNode* reverseHelper(ListNode* head) {
        if (!head || !head->next) {
            return head;
        }
        ListNode * curr = head;
        ListNode * next = nullptr;
        ListNode * prev = nullptr;

        while (curr) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (k == 1 || !head || !head->next) {
            return head;
        }

        ListNode * start = nullptr;
        ListNode * end = nullptr;
        ListNode * nhead = nullptr;
        ListNode * tail = nullptr;

        while (head) {
            start = head;
            int n = k;
            while (n && head) {
                end = head;
                head = head->next;
                n--;
            }
            end->next = nullptr;

            if (n == 0) {
                cout<<"Here"<<endl;
                if (!nhead) {
                    nhead = reverseHelper(start);
                    tail = start;
                }
                else{
                    tail->next = reverseHelper(start);
                    tail = start;
                }
            }
            else {
                 if (!nhead) {
                    nhead = start;
                    
                }
                else{
                    tail->next = start;
                    
                }   
            }
        }

        return nhead;
    }
};
