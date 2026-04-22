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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode * head = nullptr;
        ListNode * tail = nullptr;

        if (!l1) {
            return l2;
        }

        if (!l2) {
            return l1;
        }

        int sum = 0, carry = 0;

        while (l1 && l2) {
            sum = l1->val + l2->val + carry;
            ListNode * newNode = new ListNode(sum%10);
            carry = sum/10;
            l1 = l1->next;
            l2 = l2->next;
            if (!head) {
                head = newNode;
                tail = head;
            }
            else {
                tail->next = newNode;
                tail = tail->next;
            }
        }

        while (l1) {
            sum = l1->val + carry;
            ListNode * newNode = new ListNode(sum%10);
            carry = sum/10;
            l1 = l1->next;
            tail->next = newNode;
            tail = tail->next;
        }

        while(l2) {
            sum = l2->val + carry;
            ListNode * newNode = new ListNode(sum%10);
            carry = sum/10;
            l2 = l2->next;
            tail->next = newNode;
            tail = tail->next;
        }

        if (carry) {
            ListNode * newNode = new ListNode(carry);
            tail->next = newNode;
            tail = tail->next;

        }

        return head;
    }
};
