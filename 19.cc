/**
 * Definition for singly-linked list.
 */
#define NULL nullptr

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode *first, *second;
        first = second = dummy;
        for(int i = 1; i <= n + 1 && first != NULL; i ++)
            first = first->next;
        while(first != NULL) {
            first = first->next;
            second = second->next;
        }
        ListNode* tmp = second->next;
        second->next = tmp->next;
        delete tmp;
        return dummy->next;
    }
};
