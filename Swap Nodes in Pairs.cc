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
    ListNode *swapPairs(ListNode *head) {
        ListNode *first = head, *second, *next, *prev = NULL;
        while (first && first->next) {
            second = first->next;
            next = second->next;
            second->next = first;
            if (prev) {
                prev->next = second;
            } else {
                head = second;
            }
            prev = first;
            first = next;
        }
        if (prev) {
            prev->next = first;
        }
        return head;
    }
};
