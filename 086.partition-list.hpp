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
    ListNode* partition(ListNode* head, int x) {
        ListNode *dumbHead1 = new ListNode(0), *dumbHead2 = new ListNode(0);
        ListNode *p1 = dumbHead1, *p2 = dumbHead2;
        for(ListNode *p = head; p != NULL; p = p->next) {
            if(p->val < x) {
                p1->next = p;
                p1 = p1->next;
            } else {
                p2->next = p;
                p2 = p2->next;
            }
        }
        p1->next = dumbHead2->next;
        p2->next = NULL;
        return dumbHead1->next;
    }
};
