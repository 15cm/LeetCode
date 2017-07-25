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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode *dumbHead = new ListNode(0);
        dumbHead->next = head;
        ListNode *first = dumbHead;
        for(int i = 1; i < m; i++) first = first->next;
        ListNode *last = first->next, *cur = last, *succ = last->next;
        for(int i = m; i < n; i++) {
            ListNode *tmp = succ->next;
            succ->next = cur;
            cur = succ;
            succ = tmp;
        }
        first->next = cur;
        last->next = succ;
        return dumbHead->next;
    }
};
