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
    ListNode* sortList(ListNode* head) {
        return mergeSort(head);
    }
    ListNode* mergeSort(ListNode* head) {
        if(!head || !head->next) return head;
        auto slow = head, fast = head->next;
        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        auto right = slow->next;
        slow->next = NULL;
        return merge(mergeSort(head), mergeSort(right));
    }
    ListNode* merge(ListNode* l1, ListNode* l2) {
        ListNode dummy_stack(-1);
        auto dummy = &dummy_stack, cur = dummy;
        for(auto p1 = l1, p2 = l2; p1 || p2;) {
            if(p1 && p2) {
                if(p1->val <= p2->val) {
                    appendAndForward(cur, p1);
                } else {
                    appendAndForward(cur, p2);
                }
            } else if(p1) {
                appendAndForward(cur, p1);
            } else {
                appendAndForward(cur, p2);
            }
        }
        return dummy->next;
    }
    void appendAndForward(ListNode*& cur, ListNode*& p) {
        cur->next = p;
        cur = cur->next;
        p = p->next;
    }
};
