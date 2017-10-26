/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        for(TreeLinkNode *cur = root, *prev = NULL, *head = NULL; cur; cur = head, prev = NULL, head = NULL) {
            for(auto x = cur; x; x = x->next) {
                helper(x->left, prev, head);
                helper(x->right, prev, head);
            }
        }
    }
    void helper(TreeLinkNode *node, TreeLinkNode* &prev, TreeLinkNode* &head) {
        if(!node) return;
        if(prev) {
            prev->next = node;
        } else {
            head = node;
        }
        prev = node;
    }
};
