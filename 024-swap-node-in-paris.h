/**
 * Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
 */

#define NULL nullptr

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(head == NULL) return NULL;
        ListNode dummy(0);
        ListNode *prev = &dummy;
        prev->next = head;
        ListNode *succ = prev->next->next;
        while(succ != NULL) {
            ListNode *tmp = prev->next;
            prev->next = succ;
            tmp->next = succ->next;
            succ->next = tmp;
            succ = tmp;
            if(succ->next == NULL) return dummy.next;
            prev = succ;
            succ = succ->next->next;
        }
        return dummy.next;
    }
};
