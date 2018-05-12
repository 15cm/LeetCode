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
        vector<int> ans;
        dfs(root, 0, ans);
        return ans;
    }
    void dfs(TreeNode *node, int level, vector<int> &ans) {
        if(!node) return;
        if(level >= ans.size()) {
            ans.push_back(node->val);
        } else {
            ans[level] = max(ans[level], node->val);
        }
        dfs(node->left, level + 1, ans);
        dfs(node->right, level + 1, ans);
    }
};
