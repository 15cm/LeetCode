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
    void flatten(TreeNode* root) {
        dfs(root);
    }
    TreeNode* dfs(TreeNode* root) {
        if(!root) return NULL;
        auto rightNode = root->right;
        root->right = dfs(root->left);
        root->left = NULL;
        auto x = root;
        while(x->right) x = x->right;
        x->right = dfs(rightNode);
        return root;
    }
};
