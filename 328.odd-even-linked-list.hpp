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
    ListNode* oddEvenList(ListNode* head) {
        auto h1 = new ListNode(0), h2 = new ListNode(0);
        auto p1 = h1, p2 = h2;
        bool isOdd = true;
        for(auto p = head; p; p = p->next) {
            if(isOdd) {
                p1 = p1->next = p;
            } else {
                p2 = p2->next = p;
            }
            isOdd = !isOdd;
        }
        p1->next = h2->next;
        p2->next = NULL;
        return h1->next;
    }
};
