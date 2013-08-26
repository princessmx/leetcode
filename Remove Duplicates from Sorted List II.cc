// Small: 4ms; Large: 92ms
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
  ListNode *deleteDuplicates(ListNode *head) {
    set<int> exist_values;
    set<int> duplicate_values;
    ListNode *p = head, *q = NULL;
    while (p) {
      if (exist_values.count(p->val) != 0) {
        q->next = p->next;
        duplicate_values.insert(p->val);
        delete p;
      } else {
        exist_values.insert(p->val);
        q = p;
      }
      p = q->next;
    }
    p = head, q = NULL;
    while (p) {
      if (duplicate_values.count(p->val) != 0) {
        if (q) {
          q->next = p->next;
          delete p;
          p = q->next;
        } else {
          head = p->next;
          delete p;
          p = head;
        }
      } else {
        q = p;
        p = p->next;
      }
    }
    return head;
  }
};
