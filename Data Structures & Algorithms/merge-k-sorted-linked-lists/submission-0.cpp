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
    ListNode * mergeHelper(ListNode * l1, ListNode * l2) {
        if (!l1) {
            return l2;
        }
        if (!l2) {
            return l1;
        }

        ListNode * head = nullptr;
        ListNode * tail = nullptr;
        ListNode * temp = nullptr;

        while (l1 && l2) {
            if (l1->val < l2->val) {
                temp = l1;
                l1 = l1->next;
            }
            else {
                temp = l2;
                l2 = l2->next;
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

        if (l1) {
            tail->next = l1;
        }

        if (l2) {
            tail->next = l2;
        }

        return head;
    }

    ListNode * sortHelper(vector<ListNode*>& lists, int s, int e) {
        if (s > e) {
            return nullptr;
        }
        if (s == e) {
            return lists[s];
        }

        int mid = (s + e)/2;
        auto left = sortHelper(lists, s, mid);
        auto right = sortHelper(lists, mid + 1, e);
        return mergeHelper(left, right);
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();
        return sortHelper(lists, 0, n - 1);
    }
};
