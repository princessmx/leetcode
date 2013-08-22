// Small: 8ms; Large: 20ms
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
  ListNode *reverseBetween(ListNode *head, int m, int n) {
    if (m == n) {
      return head;
    }
    ListNode *q = head, *p = NULL, *r = NULL, *prev, *first;
    int count = 1;
    while (count < m) {
      p = q;
      q = q->next;
      count++;
    }
    prev = p;
    first = q;
    r = q->next;
    while (count < n) {
      p = q;
      q = r;
      r = r->next;
      q->next = p;
      count++;
    }
    if (prev) {
      prev->next = q;
    } else {
      head = q;
    }
    first->next = r;
    return head;
  }
};
