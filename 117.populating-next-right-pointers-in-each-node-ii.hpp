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
        TreeLinkNode *succ = NULL, *head = NULL, *cur = root;
        while(cur) {
            while(cur) {
                if(cur->left) {
                    if(succ) {
                        succ->next = cur->left;
                    } else {
                        head = cur->left;
                    }
                    succ = cur->left;
                }
                if(cur->right) {
                    if(succ) {
                        succ->next = cur->right;
                    }  else {
                        head = cur->right;
                    }
                    succ = cur->right;
                }
                cur = cur->next;
            }
            cur = head;
            succ = head = NULL;
        }
    }
};
