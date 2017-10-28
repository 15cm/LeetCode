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
    int findBottomLeftValue(TreeNode* root) {
        int ans = -1;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            ans = q.front()->val;
            int sz = q.size();
            while(sz--) {
                auto x = q.front(); q.pop();
                if(x->left) q.push(x->left);
                if(x->right) q.push(x->right);
            }
        }
        return ans;
    }
};
