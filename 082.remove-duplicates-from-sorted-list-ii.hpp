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
        if(head == NULL || head->next == NULL) return head;
        ListNode* dumbHead = new ListNode(0);
        dumbHead->next = head;
        ListNode *prev = dumbHead, *cur = head, *succ = head->next;
        while(true) {
            while(succ != NULL && succ->val == cur->val) succ = succ->next;
            if(cur->next == succ) {
                prev->next = cur;
                prev = prev->next;
            }
            if(succ == NULL) {
                if(cur->next != succ) prev->next = NULL;
                break;
            }
            cur = succ;
            succ = succ->next;
        }
        return dumbHead->next;
    }
};
