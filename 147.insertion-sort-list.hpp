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
    ListNode* insertionSortList(ListNode* head) {
        if(!head) return head;
        auto dummy = new ListNode(-1);
        dummy->next = head;
        for(auto cur = head->next, prev = head; cur != NULL;) {
            auto p = dummy;
            while(p->next->val < cur->val) p = p->next;
            if(p->next != cur) {
                auto tmp_cur = cur->next;
                auto tmp_p = p->next;
                p->next = cur;
                cur->next = tmp_p;
                prev->next = tmp_cur;
                cur = tmp_cur;
            } else {
                cur = cur->next;
                prev = prev->next;
            }
        }
        return dummy->next;
    }
};
