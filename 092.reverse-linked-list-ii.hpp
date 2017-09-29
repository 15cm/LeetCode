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
        auto dummy = new ListNode(0);
        dummy->next = head;
        auto left = dummy, cur = head;
        for(int i = 1; i < m; i++) {
            left = left->next;
            cur = cur->next;
        }
        auto right = cur;
        ListNode* prev = NULL, *t;
        for(int i = m; i <= n; i++) {
            t = cur->next;
            cur->next = prev;
            prev = cur;
            cur = t;
        }
        left->next = prev;
        right->next = cur;
        return dummy->next;
    }
};
