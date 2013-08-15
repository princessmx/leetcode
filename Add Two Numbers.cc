// Small: 8ms; Large: 180ms
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
  ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
    if (!l1) {
      return l2;
    }
    if (!l2) {
      return l1;
    }
    ListNode *res = NULL, *last = NULL, *p;
    int carry = 0;
    while (l1 && l2) {
      int sum = l1->val + l2->val + carry;
      p = new ListNode(sum % 10);
      if (last) {
        last->next = p;
      } else {
        res = p;
      }
      last = p;
      carry = sum / 10;
      l1 = l1->next;
      l2 = l2->next;
    }
    if (l2) {
      l1 = l2;
    }
    while (l1) {
      int sum = l1->val + carry;
      p = new ListNode(sum % 10);
      last->next = p;
      last = p;
      carry = sum / 10;
      l1 = l1->next;
    }
    if (carry) {
      p = new ListNode(carry);
      last->next = p;
    }
    return res;
  }
};
