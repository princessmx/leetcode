// Small: 4ms; Large: 36ms
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
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        ListNode *fast = head, *slow = head, *prev = NULL;
        for (int i = 1; i < n; i++) {
            fast = fast->next;
        }
        while (fast->next != NULL) {
            prev = slow;
            slow = slow->next;
            fast = fast->next;
        }
        if (prev) {
            prev->next = slow->next;
        } else {
            head = slow->next;
        }
        delete slow;
        return head;
    }
};
