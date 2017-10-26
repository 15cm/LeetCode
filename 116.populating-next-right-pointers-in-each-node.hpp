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
        for(auto cur = root; cur; cur = cur->left) {
            for(auto x = cur; x; x = x->next) {
                if(x->left) {
                    x->left->next = x->right;
                }
                if(x->right && x->next) {
                    x->right->next = x->next->left;
                }
            }
        }
    }
};
