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
    ListNode* plusOne(ListNode* head) {
        int v = helper(head);
        if(v == 1) {
            auto h = new ListNode(1);
            h->next = head;
            return h;
        }
        return head;
    }
    int helper(ListNode* node) {
        if(!node) return 1;
        int v = node->val + helper(node->next);
        if(v == 10) {
            node->val = 0;
            return 1;
        } else {
            node->val = v;
            return 0;
        }
    }
};
