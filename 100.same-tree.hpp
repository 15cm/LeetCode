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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        queue<TreeNode*> queue1, queue2;
        queue1.push(p);
        queue2.push(q);
        while(!queue1.empty() && !queue2.empty()) {
            TreeNode* _p = queue1.front(); queue1.pop();
            TreeNode* _q = queue2.front(); queue2.pop();
            if(!((!_p && !_q) || (_p && _q && _p->val == _q->val)))
                return false;
            if(_p) {
                queue1.push(_p->left);
                queue1.push(_p->right);
            }
            if(_q) {
                queue2.push(_q->left);
                queue2.push(_q->right);
            }
        }
        if(!queue1.empty() || !queue2.empty()) return false;
        return true;
    }
};
