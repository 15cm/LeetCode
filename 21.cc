/**
 * Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
 * };
 */

#define NULL nullptr

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *dummy = new ListNode(0);
        ListNode *dummyHead = dummy;
        while(l1 != NULL && l2 != NULL) {
            if(l1->val < l2->val) {
                dummy->next = l1;
                l1 = l1->next;
            } else {
                dummy->next = l2;
                l2 = l2->next;
            }
            dummy = dummy->next;
        }
        for(; l1 != NULL; l1 = l1->next) {
            dummy->next = l1;
            dummy = dummy->next;
        }
        for(; l2 != NULL; l2 = l2->next) {
            dummy->next = l2;
            dummy = dummy->next;
        }
        dummy->next = NULL;
        return dummyHead->next;
    }
};
