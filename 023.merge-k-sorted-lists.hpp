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
        return lists.empty() ? NULL : mergeKLists(lists, 0, lists.size() - 1);
    }
    ListNode* mergeKLists(vector<ListNode*>& lists, int lo, int hi) {
        if(lo == hi) return lists[lo];
        int mid = lo + (hi - lo) / 2;
        auto l1 = mergeKLists(lists, lo, mid);
        auto l2 = mergeKLists(lists, mid + 1, hi);
        return merge(l1, l2);
    }
    ListNode* merge(ListNode* l1, ListNode* l2) {
        if(!l1) return l2;
        if(!l2) return l1;
        if(l1->val < l2->val) {
            l1->next = merge(l1->next, l2);
            return l1;
        } else {
            l2->next = merge(l1, l2->next);
            return l2;
        }
    }
};
