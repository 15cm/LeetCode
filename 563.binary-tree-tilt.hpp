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
    int findTilt(TreeNode* root) {
        int ans = 0;
        dfs(root, ans);
        return ans;
    }
    int dfs(TreeNode *node, int &ans) {
        if(!node) return 0;
        int left = dfs(node->left, ans);
        int right = dfs(node->right, ans);
        ans += abs(left - right);
        return node->val + left + right;
    }
};
