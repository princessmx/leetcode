/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        counterpart_.clear();
        RandomListNode *copy_head = NULL, *cur = head, *copy_cur, *copy_prev = NULL;
        while (cur) {
            copy_cur = new RandomListNode(cur->label);
            if (copy_prev) {
                copy_prev->next = copy_cur;
            } else {
                copy_head = copy_cur;
            }
            counterpart_[cur] = copy_cur;
            copy_cur->random = cur->random;
            copy_prev = copy_cur;
            cur = cur->next;
        }
        for (copy_cur = copy_head; copy_cur; copy_cur = copy_cur->next) {
            if (copy_cur->random) {
                copy_cur->random = counterpart_[copy_cur->random];
            }
        }
        return copy_head;
    }
private:
    map<RandomListNode *, RandomListNode *> counterpart_;
};
