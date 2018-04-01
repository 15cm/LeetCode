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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int n = 0, m = 0;
        for(auto p = l1; p; p = p->next) n++;
        for(auto p = l2; p; p = p->next) m++;
        if(m > n) {
            swap(l1, l2);
            swap(m, n);
        }
        auto ans = add(l1, l2, n-m);
        if(ans && ans->val >= 10) {
            ans->val -= 10;
            auto tmp = new ListNode(1);
            tmp->next = ans;
            ans = tmp;
        }
        return ans;
    }
    ListNode* add(ListNode* p, ListNode* q, int k) {
        if(!p || !q) return NULL;
        ListNode* res;
        if(k)
            res = add(p->next, q, k-1);
        else
            res = add(p->next, q->next, k);
        int carry = 0;
        if(res && res->val >= 10) {
            res->val -= 10;
            carry = 1;
        }
        auto t = new ListNode(p->val + (k == 0 ? q->val : 0) + carry);
        t->next = res;
        return t;
    }
};
