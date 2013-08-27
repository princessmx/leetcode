// Small: 8ms; Large: 84ms
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
  ListNode *mergeKLists(vector<ListNode *> &lists) {
    vector<ListNode *> k_heap;
    for (int i = 0; i < lists.size(); i++) {
      if (lists[i]) {
        k_heap.push_back(lists[i]);
      }
    }
    make_heap(k_heap.begin(), k_heap.end(), ListNodeGT());
    ListNode *node, *res = NULL, *prev;
    while (!k_heap.empty()) {
      node = k_heap.front();
      pop_heap(k_heap.begin(), k_heap.end(), ListNodeGT());
      k_heap.pop_back();
      if (!res) {
        res = node;
      } else {
        prev->next = node;
      }
      prev = node;
      if (node->next) {
        k_heap.push_back(node->next);
        push_heap(k_heap.begin(), k_heap.end(), ListNodeGT());
      }
    }
    return res;
  }
 private:
  struct ListNodeGT {
    bool operator()(ListNode *&n1, ListNode *&n2) {
      return n1->val > n2->val;
    }
  };
};
