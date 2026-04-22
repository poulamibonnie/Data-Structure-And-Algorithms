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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* prev = nullptr;
        ListNode * fast = head;
        ListNode * slow = head;

        while (n) {
            fast = fast->next;
            n--;
        }

        while(fast) {
            fast = fast->next;
            prev = slow;
            slow = slow->next;
        }

        if (!prev) {
            return slow->next;
        }
        else {
            prev->next = slow->next;
        }

        return head;
    }
};
