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
        dfs(root, 1, ans);
        return ans;
    }
    void dfs(TreeNode* node, int level, vector<int> &res) {
        if(!node) return;
        if(res.size() < level) res.push_back(node->val);
        dfs(node->right, level+1, res);
        dfs(node->left, level+1, res);
    }
};
