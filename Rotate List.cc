// Small: 12ms; Large: 68ms
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
    ListNode *rotateRight(ListNode *head, int k) {
        if (head == NULL) {
            return NULL;
        }
        ListNode *tail = head;
        int len = 1;
        while (tail->next != NULL) {
            tail = tail->next;
            len++;
        }
        k %= len;
        if (k > 0) {
            tail->next = head;
            k = len - k;
            tail = head;
            while (k > 1) {
                tail = tail->next;
                k--;
            }
            head = tail->next;
            tail->next = NULL;
        }
        return head;
    }
};
