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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty()) return NULL;
        int n = lists.size();
        for(int sz = 1; sz < n; sz += sz) {
            for(int i = 0; i + sz < n; i += sz*2) {
                lists[i] = merge(lists[i], lists[i + sz]);
            }
        }
        return lists[0];
    }
    ListNode* merge(ListNode* l1, ListNode* l2) {
        auto dummy = new ListNode(0), cur = dummy, p = l1, q = l2;
        for(; p && q; cur = cur->next) {
            if(p->val < q->val) {
                cur->next = p;
                p = p->next;
            } else {
                cur->next = q;
                q = q->next;
            }
        }
        if(!p) cur->next = q;
        else cur->next = p;
        return dummy->next;
    }
};
