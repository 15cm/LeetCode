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
    ListNode *detectCycle(ListNode *head) {
        ListNode *slow, *fast;
        slow = fast = head;
        do {
            if(!fast || !fast->next) return NULL;
            slow = slow->next;
            fast = fast->next->next;
        } while(slow != fast);
        auto p1 = head, p2 = slow;
        for(; p1 != p2; p1 = p1->next, p2 = p2->next);
        return p1;
    }
};
