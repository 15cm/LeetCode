/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        return build(head, NULL);
    }
    TreeNode* build(ListNode* head, ListNode* tail) {
        if(head == tail) return NULL;
        ListNode *slow = head, *fast = head;
        while(fast != tail && fast->next != tail) {
            fast = fast->next->next;
            slow = slow->next;
        }
        auto root = new TreeNode(slow->val);
        root->left = build(head, slow);
        root->right = build(slow->next, tail);
        return root;
    }
};
