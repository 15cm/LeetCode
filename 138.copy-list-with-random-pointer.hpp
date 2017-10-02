/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */

typedef RandomListNode N;
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        N *p = head, *q;
        while(p) {
            q = p->next;
            p->next = new N(p->label);
            p->next->next = q;
            p = q;
        }

        p = head;
        while(p) {
            if(p->random)
                p->next->random = p->random->next;
            p = p->next->next;
        }

        N *dummy = new N(0);
        N *copy, *copyIter = dummy;
        p = head;
        while(p) {
            q = p->next->next;
            copyIter->next = p->next;
            copyIter = p->next;

            p->next = q;
            p = q;
        }
        return dummy->next;
    }
};
