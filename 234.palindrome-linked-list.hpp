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
    bool isPalindrome(ListNode* head) {
        auto slow = head, fast = head;
        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        if(fast) slow = slow->next;
        auto head2 = reverseLinkedList(slow);
        for(auto p = head, q = head2; q; p = p->next, q = q->next) {
            if(p->val != q->val) return false;
        }
        return true;
    }
    ListNode* reverseLinkedList(ListNode* head) {
        ListNode* cur = NULL;
        for(auto p = head; p;) {
            auto tmp = p->next;
            p->next = cur;
            cur = p;
            p = tmp;
        }
        return cur;
    }
};
