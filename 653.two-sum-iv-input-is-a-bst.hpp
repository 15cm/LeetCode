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
    bool findTarget(TreeNode* root, int k) {
        stack<TreeNode*> lstk, rstk;
        pushAll(root, lstk, true);
        pushAll(root, rstk, false);
        while(!(lstk.empty() || rstk.empty() || lstk.top() == rstk.top())) {
            auto lnode = lstk.top(), rnode = rstk.top();
            int diff = lnode->val + rnode->val - k;
            if(diff == 0) return true;
            else if(diff < 0) {
                lstk.pop();
                pushAll(lnode->right, lstk, true);
            } else {
                rstk.pop();
                pushAll(rnode->left, rstk, false);
            }
        }
        return false;
    }
    void pushAll(TreeNode *node, stack<TreeNode*> &stk, bool shouldPushLeft) {
        while(node) {
            stk.push(node);
            node = (shouldPushLeft ? node->left : node->right);
        }
    }
};
