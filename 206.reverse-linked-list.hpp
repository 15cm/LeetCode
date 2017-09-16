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
    // Iteratively
    // ListNode* reverseList(ListNode* head) {
    //     ListNode* cur = NULL;
    //     for(auto p = head; p != NULL;) {
    //         auto tmp = p->next;
    //         p->next = cur;
    //         cur = p;
    //         p = tmp;
    //     }
    //     return cur;
    // }
    // Recursively
    ListNode* reverseList(ListNode* head) {
        if(!head || !head->next) return head;
        auto p = reverseList(head->next);
        head->next->next = head;
        head->next = NULL;
        return p;
    }
};
