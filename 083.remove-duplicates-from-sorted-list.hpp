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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *dumbHead = new ListNode(0);
        dumbHead->next = head;
        ListNode *h = dumbHead;
        for(ListNode *p = head; p != NULL; p = p->next) {
            if(p->next == NULL || p->val != p->next->val) {
                h->next = p;
                h = h->next;
            }
        }
        return dumbHead->next;
    }
};
