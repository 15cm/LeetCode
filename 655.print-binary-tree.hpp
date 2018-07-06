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
    vector<vector<string>> printTree(TreeNode* root) {
        int h = getHeight(root);
        vector<vector<string>> ans(h, vector<string>((1 << h) - 1));
        dfs(root, 0, 0, ans[0].size(), ans);
        return ans;
    }
    void dfs(TreeNode *node, int depth, int l, int r, vector<vector<string>> &ans) {
        if(!node) return;
        int mid = l + (r - l) / 2;
        ans[depth][mid] = to_string(node->val);
        dfs(node->left, depth + 1, l, mid, ans);
        dfs(node->right, depth + 1, mid + 1, r, ans);
    }
    int getHeight(TreeNode *node) {
        if(!node)return NULL;
        return 1 + max(getHeight(node->left), getHeight(node->right));
    }
};
