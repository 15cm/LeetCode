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
    ListNode* removeElements(ListNode* head, int val) {
        auto fh = new ListNode(0);
        auto x = fh;
        for(; head; head = head->next) {
            if(head->val != val) {
                x->next = head;
                x = x->next;
            }
        }
        if(x) x->next = NULL;
        return fh->next;
    }
};
