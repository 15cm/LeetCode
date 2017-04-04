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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode dummy(0);
        ListNode* prev = &dummy;
        prev->next = head;
        ListNode* succ = prev;
        for(int i = 0; i < k; i ++)
            if(succ == NULL) return dummy.next;
            else succ = succ->next;
        while(succ != NULL) {
            ListNode* oldHead = prev->next;
            ListNode* oldTail = succ;
            succ = succ->next;
            oldTail->next = NULL;
            prev->next = reverseLinkList(NULL, oldHead);
            oldHead->next = succ;
            prev = oldHead;
            for(int i = 1; i <= k - 1 && succ != NULL; i ++, succ = succ->next);
        }
        return dummy.next;
    }
    ListNode* reverseLinkList(ListNode* rl, ListNode* l) {
        if(l == NULL) return rl;
        ListNode* tmp = l->next;
        l->next = rl;
        rl = l;
        return reverseLinkList(rl, tmp);
    }
};
