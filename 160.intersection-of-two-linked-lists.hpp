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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        auto p1 = headA, p2 = headB;
        int cnt = 0;
        if(!p1 || !p2) return NULL;
        while(p1 != p2) {
            p1 = p1->next;
            p2 = p2->next;
            if(!p1) {
                p1 = headB;
                cnt++;
            }
            if(!p2) {
                p2 = headA;
                cnt++;
            }
            if(cnt > 2) return NULL;
        }
        return p1;
    }
};
