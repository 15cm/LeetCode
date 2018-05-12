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
    vector<int> largestValues(TreeNode* root) {
        if(!root) return {};
        vector<int> ans;
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()) {
            int sz = q.size();
            int maxv = INT_MIN;
            while(sz--) {
                auto u = q.front(); q.pop();
                maxv = max(maxv, u->val);
                if(u->left) q.push(u->left);
                if(u->right) q.push(u->right);
            }
            ans.push_back(maxv);
        }
        return ans;
    }
};
