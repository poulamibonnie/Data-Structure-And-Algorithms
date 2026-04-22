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
public:
    ListNode * reverseHelper(ListNode * head) {
        if (!head || !head->next) {
            return head;
        }
        ListNode * curr = head;
        ListNode * prev = nullptr;
        ListNode * next = nullptr;

        while (curr) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }

    ListNode * midHelper(ListNode * head, ListNode ** prev) {
        if (!head || !head->next) {
            return head;
        }

        ListNode * fast = head;
        ListNode * slow = head;
        

        while(fast) {
            fast = fast->next;
            if (fast) {
                fast = fast->next;
                *prev = slow;
                slow = slow->next;
            }
        }

        return slow;
    }

    void reorderList(ListNode* head) {
        if (!head || !head->next) {
            return;
        }
        ListNode * prev = nullptr;
        ListNode * middle = reverseHelper(midHelper(head, &prev));
        prev->next = nullptr;

        ListNode * nhead = nullptr;
        ListNode * tail = nullptr;
        ListNode * temp = nullptr;

        while (head && middle) {
            temp = head;
            head = head->next;
            temp->next = middle;
            middle = middle->next;
            temp->next->next = nullptr;
            if (!nhead) {
                nhead = temp;
                tail = temp->next;
            }
            else {
                tail->next = temp;
                tail = temp->next;
            }
        }

        if (middle) {
            tail->next = middle;
            
        }
    }
};
