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
    void deleteNode(ListNode* node) {
        if(node) {
            if(!node->next) {
                node = NULL;
            } else {
                swap(node->val, node->next->val);
                auto x = node->next;
                node->next = x->next;
                delete x;
            }
        }
    }
};
