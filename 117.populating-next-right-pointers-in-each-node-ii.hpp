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
        TreeLinkNode *pre = root, *first, *second, *head, *tmp, *cur;
        while(pre) {
            cur = pre;
            head = first = second = NULL;
            while(cur) {
                if(cur->left) {
                    tmp = cur->left;
                    if(first) {
                        if(second) {
                            first = second;
                            second = second->next = tmp;
                        } else {
                            first->next = second = tmp;
                        }
                    } else {
                        head = tmp;
                        first = tmp;
                    }
                }
                if(cur->right) {
                    tmp = cur->right;
                    if(first) {
                        if(second) {
                            first = second;
                            second = second->next = tmp;
                        } else {
                            first->next = second = tmp;
                        }
                    } else {
                        head = tmp;
                        first = tmp;
                    }
                }
                cur = cur->next;
            }
            pre = head;
        }
    }
};
