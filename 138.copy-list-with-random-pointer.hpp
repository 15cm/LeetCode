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
        unordered_map<RandomListNode*, RandomListNode*> mp;
        RandomListNode *h = new RandomListNode(0);
        for(auto p = head, cur = h; p != NULL; p = p->next, cur = cur->next) {
            RandomListNode *x = new RandomListNode(p->label);
            mp[p] = x;
            cur->next = x;
        }
        for(auto p1 = head, p2 = h->next; p1 != NULL; p1 = p1->next, p2 = p2 ->next) {
            p2->random = mp[p1->random];
        }
        return h->next;
    }
};
