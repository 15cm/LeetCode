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
    void reorderList(ListNode* head) {
        if(!head || !head->next || !head->next->next) return;
        auto slow = head, fast = head;
        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        auto before_mid = slow, mid = before_mid->next, cur = mid->next;
        // Reverse latter half
        mid->next = NULL;
        while(cur) {
            auto tmp = cur->next;
            cur->next = mid;
            mid = cur;
            cur = tmp;
        }
        before_mid->next = NULL;

        auto p = head, q = mid;
        while(q != NULL) {
            auto tmpp = p->next, tmpq = q->next;
            p->next = q;
            q->next = tmpp;
            p = tmpp; q = tmpq;
        }
    }
};
