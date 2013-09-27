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
    ListNode *reverseKGroup(ListNode *head, int k) {
        if (k <= 1) {
            return head;
        }
        ListNode *prev = NULL, *start = head, *end, *next;
        int count;
        while (start) {
            count = 1;
            end = start;
            while (end->next && count < k) {
                end = end->next;
                count++;
            }
            next = end->next;
            if (count == k) {
                reverse(start, end);
                if (prev != NULL) {
                    prev->next = end;
                } else {
                    head = end;
                }
                prev = start;
                prev->next = NULL;
            } else if (prev != NULL) {
                prev->next = start;
            }
            if (!end) {
                break;
            }
            start = next;
        }
        return head;
    }
private:
    void reverse(ListNode *start, ListNode *end) {
        ListNode *prev = start, *cur = start->next, *next;
        while (prev != end) {
            next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
    }
};
