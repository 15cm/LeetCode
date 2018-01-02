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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if(!root) return ans;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            int sz = q.size();
            while(sz--) {
                auto x = q.front(); q.pop();
                if(x->left) q.push(x->left);
                if(x->right) q.push(x->right);
                if(sz == 0)
                    ans.push_back(x->val);
            }
        }
        return ans;
    }
};
