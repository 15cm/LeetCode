#define NULL nullptr
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* l = new ListNode(0);
        ListNode* head = l;
        int carry = 0;
        while(l1 != NULL || l2 != NULL) {
            int v1 = l1 == NULL ? 0 : l1->val;
            int v2 = l2 == NULL ? 0 : l2->val;
            int sum = v1 + v2 + carry;
            carry = 0;
            if (sum >= 10) {
                sum -= 10;
                carry = 1;
            }
            l->val = sum;
            if(l1 != NULL) l1 = l1->next;
            if(l2 != NULL) l2 = l2->next;
            if(l1 != NULL || l2 != NULL || carry > 0) {
                l->next = new ListNode(0);
                l = l->next;
            }
        }
        if(carry == 1) l->val = 1;
        return head;
    }
};
