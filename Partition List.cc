// Small: 20ms; Large: 52ms
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
    ListNode *partition(ListNode *head, int x) {
        if (!head || !head->next) {
            return head;
        }
        ListNode *tail = head;
        while (tail->next) {
            tail = tail->next;
        }
        ListNode *h = new ListNode(INT_MIN);
        h->next = head;
        ListNode *pre = h, *p = head, *q = tail;
        while (p != q) {
            if (p->val >= x) {
                tail->next = p;
                tail = p;
                pre->next = p->next;
                p->next = NULL;
            } else {
                pre = p;
            }
            p = pre->next;
        }
        if (p->val >= x) {
            tail->next = p;
            pre->next = p->next;
            p->next = NULL;
        }
        head = h->next;
        delete h;
        return head;
    }
};
