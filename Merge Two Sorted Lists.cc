// Small: 8ms; Large: 56ms
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        if (l1 == NULL) {
            return l2;
        }
        if (l2 == NULL) {
            return l1;
        }
        ListNode *head = NULL, *tail = NULL;
        while (l1 && l2) {
            if (l1->val <= l2->val) {
                if (tail != NULL) {
                    tail->next = l1;
                }
                tail = l1;
                l1 = l1->next;
            } else {
                if (tail != NULL) {
                    tail->next = l2;
                }
                tail = l2;
                l2 = l2->next;
            }
            if (head == NULL) {
                head = tail;
            }
        }
        if (l1 != NULL) {
            tail->next = l1;
        } else {
            tail->next = l2;
        }
        return head;
    }
};
