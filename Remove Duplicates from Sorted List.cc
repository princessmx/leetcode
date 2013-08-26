// Small: 8ms; Large: 96ms
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
    ListNode *p = head, *q = NULL;
    while (p) {
      if (exist_values.count(p->val) != 0) {
        q->next = p->next;
        delete p;
      } else {
        exist_values.insert(p->val);
        q = p;
      }
      p = q->next;
    }
    return head;
  }
};
