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
    vector<double> averageOfLevels(TreeNode* root) {
        if(!root) return {};
        vector<double> ans;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            double sum = 0;
            int sz = q.size();
            for(int i = 0; i < sz; i++) {
                auto node = q.front(); q.pop();
                sum += node->val;
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            sum /= sz;
            ans.push_back(sum);
        }
        return ans;
    }
};
