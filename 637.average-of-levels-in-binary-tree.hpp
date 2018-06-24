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
        vector<TreeNode*> nodes, tnodes;
        nodes.push_back(root);
        while(!nodes.empty()) {
            tnodes.clear();
            double sum = 0;
            for(auto u: nodes) {
                sum += u->val;
                if(u->left) tnodes.push_back(u->left);
                if(u->right) tnodes.push_back(u->right);
            }
            ans.push_back(sum / nodes.size());
            nodes.swap(tnodes);
        }
        return ans;
    }
};
