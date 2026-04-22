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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (!list1) {
            return list2;
        }
        if (!list2) {
            return list1;
        }

        ListNode * head = nullptr;
        ListNode * tail = nullptr;
        ListNode * temp = nullptr;

        while (list1 && list2) {
            if (list1->val <= list2->val) {
                temp = list1;
                list1 = list1->next; 
            }
            else {
                temp = list2;
                list2 = list2->next;
            }
            temp->next = nullptr;
            if (!head) {
                head = temp;
                tail = temp;
            }
            else {
                tail->next = temp;
                tail = temp;
            }
        }

        if (list1) {
            tail->next = list1;
        }

        if (list2) {
            tail->next = list2;
        } 

        return head;
    }
};
